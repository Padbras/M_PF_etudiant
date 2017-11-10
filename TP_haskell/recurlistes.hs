
taille :: [Int] -> Int
taille [] = 0
taille (x:xs) = 1 + (taille xs)

element :: Int -> [Int] -> Bool
element _ [] = False
element y (x:xs) = if  x == y
                   then True
                   else element y (xs)

mini :: [Int] -> Int
mini (x:xs) = mini' (x:xs) maxBound
  where mini' [] a = a
        mini' (x:xs) a = if x < a
                         then mini' xs x
                         else mini' xs a     
                                  
replicate' :: Int -> Int -> [Int]
replicate' 0 x = [x]
replicate' n x = replicate' (n-1) y
  where y = [x]:y


main = do
  print $ taille [1..42]
  print $ element 6 [1..5]
  print $ mini [1..5]
  print $ mini [17,89,14,8,23,5,78]
  print $ replicate' 3 5
