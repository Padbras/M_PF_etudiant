
reductionSomme :: Num a => [a] -> a
reductionSomme x = foldr (+) 0 x


reductionSomme' :: Num a => [a] -> a
reductionSomme' [] = 0
reductionSomme' (x:xs) = x + reductionSomme' xs
                  



main = do
 print $ reductionSomme [2,5,4,6]
 print $ reductionSomme' [2,5,4,6]




  
