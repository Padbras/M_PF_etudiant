data Gengens = Kekun String Gengens Gengens [Gengens] | Personne deriving (Show)

showPrenom :: Gengens -> String
showPrenom Personne = "personne"
showPrenom (Kekun n _ _ _) = n


showPere :: Gengens -> String
showPere Personne = "personne"
showPere (Kekun _ n _ _) = showPrenom n


main = do
  
  print $ showPrenom alan
  print $ showPere john
  where alan = Kekun "Alan" julius sara [Personne]
        john =  Kekun "John" julius sara [Personne]
        sara = Kekun "Sara" Personne Personne [john, alan]
        julius = Kekun "Julius" Personne Personne [john, alan] 
