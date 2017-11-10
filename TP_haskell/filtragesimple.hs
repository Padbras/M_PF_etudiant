
filtragePairs :: Integral a => [a] -> [a]
filtragePairs x = filter even  x


filtragePairs' :: Integral a => [a] -> [a]
filtragePairs' [] = []
filtragePairs' (x:xs) = if even x
                        then x:filtragePairs' xs
                        else filtragePairs' xs



main = do
 print $ filtragePairs [2,5,4,6]
 print $ filtragePairs' [2,5,4,6]




  
