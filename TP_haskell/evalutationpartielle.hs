mul42 :: Integer -> Integer
mul42  =  (*) 42 


null' :: Integer -> Bool
null' = (==) 0

main = do
 print $ mul42 2
 print $ mul42 1
 print $ null' 0
 print $ null' 2



  
