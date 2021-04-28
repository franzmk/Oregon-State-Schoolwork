import Data.Char
import Data.Typeable

--Exercise 1
--a
data Cmd = Pen Mode
           | Moveto Pos Pos
           | Def Name Pars Cmd
           | Call Name Vals
           | Show_cmd Cmd Cmd
     
data Mode = Up | Down 

data Pos = Num_pos Int
           | Name_pos Name
           
data Pars = Show_pars Name Pars 
            | Name_pars Name
--type Pars = [Name]
          
data Vals = Show_vals Int Vals
           | Num_vals Int
           
type Name = String

instance Show Mode where
    show Up = "Up"
    show Down = "Down"

instance Show Pos where
  show (Num_pos x) = show x
  show (Name_pos y) = show y 

instance Show Pars where
   show (Show_pars x y) = show x ++ ", " ++ show y 
   show (Name_pars x) = show x

instance Show Vals where
   show (Show_vals x y) = show x ++ ", " ++ show y 
   show (Num_vals x) = show x

instance Show Cmd where
   show (Pen x) = "pen " ++ show x
   show (Moveto x y) = "moveto (" ++ show x ++ "," ++ show y ++ ")"
   show (Def x y z) = "def " ++ show x ++ " ( " ++ show y ++ " ) " ++ show z 
   show (Call x y) = "call " ++ show x ++ " ( " ++ show y ++ " ) "
   show (Show_cmd x y) = show x ++"; "++ show y

mode1 :: Mode
mode1 = Up

pos1 :: Pos
pos1 = Num_pos 3

pos2 :: Pos
pos2 = Num_pos 4

pos3 :: Pos
pos3 = Name_pos "Hi"

pars1 :: Pars
pars1 = Name_pars "ABC"

pars2 :: Pars
--pars2 = Show_pars "XYZ" pars1
pars2 = Show_pars "F" (Show_pars "XYZ" (Name_pars "ABC"))

vals1 :: Vals
vals1 = Num_vals 3

vals2 :: Vals
vals2 = Show_vals 2 vals1

--b
vector :: Cmd
vector = Def "vector" (Show_pars "x1" (Show_pars "y1" (Show_pars "x2" (Name_pars "y2"))))
         (Show_cmd (Pen Up)
         (Show_cmd (Moveto (Name_pos "x1") (Name_pos "y1"))
         (Show_cmd (Pen Down)
         (Show_cmd (Moveto (Name_pos "x2") (Name_pos "y2")) (Pen Up)))))

--c
take_step :: Int -> Cmd
take_step n = Show_cmd (Pen Up) 
              (Show_cmd (Moveto (Num_pos n) (Num_pos n)) 
              (Show_cmd (Pen Down)
              (Show_cmd (Moveto (Num_pos (n-1)) (Num_pos n)) (Moveto (Num_pos (n-1)) (Num_pos (n-1))))))

steps :: Int -> Cmd
steps 0 = Pen Up
steps n = Show_cmd (take_step n) (steps (n-1))

--Exercise 2

isChar :: (Typeable a) => a -> Bool
isChar n = typeOf n == typeOf 'a'

toString :: Char -> String
toString x = [x]

--a
data RegEx = E
            | Dot
            | C Char
            | Q RegEx
            | Star RegEx
            | Plus RegEx
            | Seq RegEx RegEx
            | Or RegEx RegEx
            | Paren RegEx

instance Show RegEx where
   show E = "E"
   show Dot = "."
   show (C x) = toString x
   show (Q x) = show x ++"?"
   show (Star x) = show x ++"*"
   show (Plus x) = show x++"+"
   show (Seq x y) = show x ++ show y
   show (Or x y) = show x ++ "|"++ show y
   show (Paren x) = "("++show x++")"

str1 = "aaa"

empty1 :: RegEx
empty1 = E

dot1 :: RegEx
dot1 = Dot

or1 :: RegEx
or1 = Or dot1 empty1

char1 :: RegEx
char1 = C 'a'

char2 :: RegEx
char2 = C 'b'

parentheses1 :: RegEx
parentheses1 = Paren char1

seq1 :: RegEx
seq1 = Paren (Seq char1 char2)

regex1 :: RegEx
regex1 = Or Dot (Paren(Seq char1 char2))

--regex2 :: RegEx

--b
splits :: [a] -> [([a],[a])]
splits [] = []
splits [x] = [([],[x]),([x],[])]
splits (x:xs) = [([],x:xs)] ++ [(x:s,t) | (s,t) <- splits xs]

accept :: RegEx -> String -> Bool
accept E s = if s=="" then True else False
accept Dot x = if ((length x) == 1 && isChar(x !! 0)) then True else False
accept (C x) s = if (((length s) == 1) && (s !! 0 == x)) then True else False
accept (Paren x) s = accept x s
accept (Seq e1 e2) s = or [accept e1 v && accept e2 w | (v,w) <- splits s]
accept (Q x) s = accept x s || accept E s
accept (Star x) s = accept (Plus x) s || accept E s 
accept (Plus x) s = or [accept x v && accept (Star x) w | (v,w) <- splits s]
accept (Or x y) s = accept x s || accept y s

classify :: RegEx -> [String] -> IO ()
classify e ws = putStrLn ("ACCEPT:\n"++show acc++"\nREJECT:\n"++show rej)
   where acc = filter (accept e) ws
         rej = filter (not.(accept e)) ws

--c
--commaSep :: RegEx