import System.Environment



ou :: Bool -> Bool -> Bool -- FILTRAGE PAR MOTIF
ou False False = False 
ou _ _ = True  

ou' :: Bool -> Bool -> Bool -- EXPRESSION CONDITIONELLE
ou' (x,y) = 	if x == False && y == False
                then False
                else True


ou'' :: Bool -> Bool -> Bool -- GARDES
safetail2 x
    | length x == 0 = [""]
    | otherwise = tail x  

 

et :: Bool -> Bool -> Bool -- FILTRAGE PAR MOTIF
safetail3 [] = []  
safetail3 (x:xs) = xs   


et' :: Bool -> Bool -> Bool  -- EXPRESSION CONDITIONELLE
safetail1 x = 	if length x == 0
                then [""]
                else tail x


et'' :: Bool -> Bool -> Bool -- GARDES
safetail2 x
    | length x == 0 = [""]
    | otherwise = tail x  


main = do
 print $ safetail1 ["toto", "tata"]
 print $ safetail1 []
 print $ safetail2 ["toto", "tata"]
 print $ safetail2 []
 print $ safetail3 ["toto", "tata"]
 print $ safetail3 []


