estPair :: Integer -> Bool 
estPair = (==0).(`mod` 2)

estMemeSigne :: Integer -> Integer -> Bool
estMemeSigne x y = x*y >=0

main = do
 print $ estPair 2
 print $ estPair 3
 print $ estMemeSigne 6 15
 print $ estMemeSigne -2 1
 print $ estMemeSigne -6 -74
 print $ estPair 1


  
