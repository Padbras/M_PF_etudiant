factorielleReduction :: Int -> Int 
factorielleReduction x = foldr (*) 1 [1..x]


fibonacciReduction :: Int -> Int
fibonacciReduction x = 0

absList :: [Int] -> [Int]
absList = map abs 


maxList:: [Int] -> Int
maxList l = foldr max (head l) (tail l)

first3 :: [String] -> [String]
first3  = map (take 3)

short :: [String] -> [String]
short = filter  ((<3).length) 


main = do
 print $ factorielleReduction 5
 print $ fibonacciReduction 5
 print $ absList [2,3,(-4),5]
 print $ maxList [2,3,4,5,6]
 print $ first3 ["Toto", "Bidule", "Reponse", "Test"]
 print $ short ["Toto", "42", "Reponse"]




  
