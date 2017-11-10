import System.Environment


getElem2 :: [a] -> a
getElem2 (x:xs) = head xs



main = do
 print $ getElem2 [4,5,6]
 print $ getElem2 [1,2,3,4,5,6,7,8,9]
