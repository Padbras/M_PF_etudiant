import System.Environment


foisTroisPlusUn :: Int -> Int
foisTroisPlusUn = (\x -> x+1).(\x -> x*3)  



main = do
 print $ foisTroisPlusUn 2
 print $ foisTroisPlusUn 50
