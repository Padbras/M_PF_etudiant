
factorielleReduction :: Int -> Int 
factorielleReduction x = foldr (*) 1 [1..x]


fibonacciReduction :: Int -> Int
fibonacciReduction x = 0
                  



main = do
 print $ factorielleReduction 5
 print $ fibonacciReduction 5




  
