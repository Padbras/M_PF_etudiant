
mappingDoubler :: Num a => [a] -> [a]
mappingDoubler x = map (*2) x


mappingDoubler' :: Num a => [a] -> [a]
mappingDoubler' [] = []
mappingDoubler' (x:xs) = (*2) x : mappingDoubler' xs 

main = do
 print $ mappingDoubler [2,5,4,6]
 print $ mappingDoubler' [2,5,4,6]




  
