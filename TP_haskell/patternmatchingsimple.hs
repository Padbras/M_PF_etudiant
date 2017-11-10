null' :: [Integer] -> Bool
null' = (==[])

head' :: [a] -> a
head' (x:_) = x

tail' :: [a] -> [a]
tail' (_:xs) = xs

fst' :: (a,a) -> a
fst'(x,_) = x

snd' :: (a,a) -> a
snd' (_,y) = y 

main = do
 print $ null' [1,2]
 putStrLn $ if null' [1,2] == False
           then ("Liste non vide")
	   else ("Liste vide")
 print $ null' []
 print $ head' [1,2,3,4]
 print $ tail' [1,2,3,4]
 print $ fst' (15,16)
 print $ snd' (15,16)



