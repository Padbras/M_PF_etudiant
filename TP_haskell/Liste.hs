data Liste a = Nil | Cons a  (Liste a)

afficherListe :: Show a => Liste a -> String
afficherListe Nil = ""
afficherListe (Cons i l) = show i ++ " " ++ afficherListe l

convertListe :: [a] -> Liste a
convertListe [] = Nil
convertListe (x:xs) = (Cons x ( convertListe xs ) )

sumList :: Num a => Liste a -> a
sumList Nil = 0
sumList (Cons n l) = n + sumList l

main = do
  --print $ convertListe [1,2,3]
  print $ afficherListe l
  where l = Cons 1 (Cons 2 (Cons 3 Nil))
