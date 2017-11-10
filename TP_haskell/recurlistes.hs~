pgcd :: Int -> Int -> Int
pgcd x y = if y == 0
           then x
           else pgcd y (x `mod` y)

facto :: Int -> Int
facto x = facto' x 1
where
 | facto' :: Int -> Int -> Int
 | facto' 1 acc = acc
 | facto' x acc =  facto'(x-1)(acc*n)  

main = do
  print $ pgcd 10 2
  print $ facto 10
  
