import System.Environment


mini2 :: Int -> Int  -> Int 
mini2 x y  = 	if x <= y
                then x
                else y

mini3 :: Int -> Int -> Int -> Int
mini3 x y z = if mini2 x y == x
              then mini2 x z
              else mini2 y z     



main = do
 print $ mini2 41 2
 print $ mini3 1 5 0
