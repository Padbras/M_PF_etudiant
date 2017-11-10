import System.Environment


safetail1 :: [String] -> [String]
safetail1 x = 	if length x == 0
                then [""]
                else tail x


safetail2 :: [String] -> [String]
safetail2 x
    | length x == 0 = [""]
    | otherwise = tail x  


safetail3 :: [String] -> [String]
safetail3 [] = []  
safetail3 (x:xs) = xs   



main = do
 print $ safetail1 ["toto", "tata"]
 print $ safetail1 []
 print $ safetail2 ["toto", "tata"]
 print $ safetail2 []
 print $ safetail3 ["toto", "tata"]
 print $ safetail3 []


