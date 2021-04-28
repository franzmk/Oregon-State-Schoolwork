import HW1types

--Exercise 1
--Inserts an element into a bag
ins :: Eq a => a -> Bag a -> Bag a
ins a [] = [(a, 1)]
ins a ((x, y):xs)   | a == x = (x, y + 1):xs
                    | otherwise = (x, y):ins a xs

--Deletes an element from a bag
del :: Eq a => a -> Bag a -> Bag a
del a [] = []
del a ((x, y):xs)   | a == x && y - 1 == 0 = xs
                    | a == x = (x, y - 1):xs
                    | otherwise = (x, y):del a xs

--Takes a list of values and produces a multiset representation
bag :: Eq a => [a] -> Bag a
bag [] = []
bag (x:xs) = ins x (bag xs)

--Determines whether or not its first argument bag is contained in the second
subbag :: Eq a => Bag a -> Bag a -> Bool
subbag [] _ = True
subbag ((x,y):xs) ys = case lookup x ys of 
	Just m -> y <= m && subbag xs ys
	Nothing -> False

--Tests whether a bag is actually a set, which is the case when each element occurs only once
isSet :: Eq a => Bag a -> Bool
isSet [] = True
isSet ((x, y):xs)   | y == 1 = isSet xs
                    | otherwise = False

--Gets the size of the bag
size :: Bag a -> Int
size [] = 0
size ((x, y):xs) = y + size xs

--Exercise 2
g :: Graph
g = [(1,2),(1,3),(2,3),(2,4),(3,4)]

h :: Graph
h = [(1,2),(1,3),(2,1),(3,2),(4,4)]

--Reads the input graph and returns a list of the nodes without duplicates
nodes :: Graph -> [Node]
--nodes g = dup $ nodes' g 
nodes = dup . nodes'

--Helper functions for nodes
nodes' :: Graph -> [Node]
nodes' [] = []
nodes' ((x, y):xs) = x:y:(nodes' xs)

dup :: [Node] -> [Node]
dup [] = []
dup (x:xs)  | x `elem` xs = dup xs
	        | otherwise = x : dup xs

--Takes a user input graph and node number and returns all the successors node
suc :: Node -> Graph -> [Node]
suc _ [] = []
suc a (x:xs)    | a == (fst x) = (snd x):suc a xs
                | otherwise = suc a xs

--Removes a node together with all of its incident edges from a graph
detach :: Node -> Graph -> Graph
detach _ [] = []
detach n g = [a | a <- g , fst a /= n, snd a /= n]

--Creates a cycle of any given number
cyc :: Int -> Graph
cyc 0 = []
cyc a = [(x, x + 1) | x <- [1 .. a - 1]] ++ [(a, 1)]

--Exercise 3
f = [Pt (4,4), Circle (5,5) 3, Rect (3,3) 7 2]
--Computes the width of a shape
width :: Shape -> Length
width (Pt _) = 0
width (Circle _ r) = 2 * r
width (Rect _ w _) = w

--Computes the bounding box of a shape
--bbox  :: Shape -> BBox


--Computes the minimum x-coordinate of a shape
--minX  :: Shape -> Number


--Moves the position of a shape by a vector given by a point as its second argument
--move :: Shape -> Point -> Shape