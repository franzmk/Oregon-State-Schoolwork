--Can do this to redefine predfined functions
import Prelude hiding (not, even, head, tail)

--Necessary when using GHCi
main :: IO ()    -- This says that main is an IO action.
main = return () -- This tells main to do nothing.:

--Not function
not :: Bool -> Bool
not True = False
not False = True

--Not sure what this does
sign :: Int -> Int
--sign x = if x > 0 then 1 else if x < 0 then -1 else 0
sign x  | x>0 = 1
        | x<0 = 1
        | otherwise = 0

--Tells if int is pos
positive :: Int -> Bool
--positive x = if x>=0 then True else False
positive x  | x >= 0 = True
            | otherwise = False

--Factorial of int
fac :: Int -> Int
--fac n = if n < 2 then 1 else n * fac(n - 1)
--fac n | n < 2 = 1
--      | otherwise = n * fac(n - 1)
fac 1 = 1
fac n = n * fac(n - 1)

--nth fibonacci number
fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib n = fib(n - 1) + fib(n - 2)

--Tells if int is even
even :: Int -> Bool
even 0 = True
even 1 = False
even n = even(n - 2)

--Prints the first item of a list
head :: [a] -> a
head (x:_) = x
--head (x:xs) = x

--Prints the list minus the first item
tail :: [a] -> [a]
tail (_:xs) = xs

--Prints the nth element of a list
nth :: Int -> [a] -> a
nth 0 (x:_) = x
nth n (_:xs) = nth (n - 1) xs