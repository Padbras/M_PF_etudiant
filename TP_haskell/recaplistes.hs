map1 :: (a->b) -> [a] -> [b]
map1 f [] = []
map1 f (x:xs) = (f x): map1 f xs

map2 :: (a->b) -> [a] -> [b]
map2 f l =  [f y | y <-l]

filter1 :: (a->Bool) -> [a] -> [a]
filter1 f [] = []
filter1 f (x:xs) = if f x == True
                   then x : filter1 f xs
                   else filter1 f xs     


filter2  :: (a->Bool) -> [a] -> [a]
filter2 f l = [y | y<-l, f y == True]

doubler1 :: [Int] -> [Int]
doubler1 [] = []
doubler1 (x:xs) = (2*x):doubler1 xs

doubler2 :: [Int] -> [Int]
doubler2 l = [2*y | y<-l]

doubler3 :: [Int] -> [Int]
doubler3  = map (*2)

premiers1 :: [(a,b)] -> [a]
premiers1 [] = []
premiers1 (x:xs) = (fst x):premiers1 xs

premiers2 :: [(a,b)] -> [a]
premiers2 l = [fst y| y<-l]

premiers3 :: [(a,b)] -> [a]
premiers3 = map fst

concat1 :: [[a]] -> [a]
concat1 [] = []
concat1 (x:xs) = x ++ concat1 xs

concat2 :: [[a]] -> [a]
concat2 l = 

main = do
  print $ map (*2) [1..21]
  print $ map1 (*2) [1..21]
  print $ map2 (*2) [1..21]
  
  print $ filter1 (==2) [1,2,3]
  print $ filter2 (==2) [1,2,3,2]
  
  print $ doubler1 [2,3,4,5,6]
  print $ doubler2 [4,5,6,7,8]
  print $ doubler3 [5,6,7,8,9]
  
  print $ premiers1 [(1,2),(3,4),(5,6)]
  print $ premiers2 [(1,2),(3,4),(5,6)]
  print $ premiers3 [(1,2),(3,4),(5,6)]

  print $ concat1 [[1,2],[3,4],[5,6]]
