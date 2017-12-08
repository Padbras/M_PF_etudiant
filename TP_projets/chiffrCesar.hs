import Data.Char

decaler :: Int -> Char -> Char
decaler x a =  if isLower a then chr b
               else a                  
            where b = (((ord a - 97 ) + x) `mod` 26) + 97
 

chiffrerCesar :: Int -> String -> String
chiffrerCesar x  = map (decaler x  )

compterOccurences :: Char -> String -> Int
compterOccurences c = foldl (\n x -> if x == c then n+1 else n) 0


compterLettres :: String -> Int
compterLettres = length.(filter isLower)

frequencesUk :: [Float]
frequencesUk = [0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.02, 0.061, 0.07,
                0.002, 0.008, 0.04, 0.024, 0.067, 0.075, 0.019, 0.001, 0.06,
                0.063, 0.091, 0.028, 0.01, 0.024, 0.002, 0.02, 0.001]

calculerFrequences :: String -> [Float]
calculerFrequences t = [fromIntegral(compterOccurences x t)/n | x <- ['a'..'z']]
                         where n = fromIntegral(compterLettres t)



calculerChi2 :: [Float] -> [Float] -> Float
calculerChi2 f' f = sum(map diff (zip f' f))
where diff(x',x) = (x'-x)**2 / x

casserCesar :: String -> [Float] -> Int
casserCesar t f = snd $ minimum [(g n,n)|n <- [1..26]]
  where g x = calculcerChi2 frequencesUK (calculerFrequences(chiffrerCesar x t))

main = do
  print (ord 'a') -- donne le code ascii d'une lettre
  print (chr 98) -- donne le char associé au code ascii
  print (decaler 5 'a' )
  print (chiffrerCesar 1 "toto.")
  print (compterOccurences 'a' "tataaaat")
  print (compterLettres "toto. t")
  print (calculerFrequences "abcdefghijklmnopqrstuvwxyzzz")
