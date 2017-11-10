
tete :: [a] -> a
tete = head

fTete :: [Float] -> Float
fTete = (2*).(sqrt).(head)

doubler :: Num a => a -> a
doubler =  (*) 2

main = do
 print $ tete [2,5,4,6]
 print $ fTete [9,5,6,7]
 print $ doubler 5



  
