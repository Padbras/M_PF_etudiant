doublePlusUn :: Integer -> Integer
doublePlusUn  =  (+1).(2*)

plus42Positif :: Integer -> Bool
plus42Positif = (<=)0.(+42)

getElem2'' :: [a] -> a
getElem2'' = head.tail

main = do
 print $ doublePlusUn 2
 print $ plus42Positif (-41)
 print $ plus42Positif (-100)
 print $ getElem2'' [2,3,4,5]



  
