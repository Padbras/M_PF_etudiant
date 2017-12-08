import System.Environment

data Arbre a = Nil
                 | Noeud a (Arbre a) (Arbre a)

instance Show a => Show (Arbre a) where
  show Nil = ""
  show (Noeud x g d) = (show g) ++ " " ++ (show x) ++ (show d)

ajouterArbre ::Ord a => a -> Arbre a -> Arbre a
ajouterArbre x Nil = Noeud x Nil Nil
ajouterArbre x (Noeud n g d) = if x < n then Noeud n (ajouterArbre x g) d
                                         else Noeud n g (ajouterArbre x g) 


construireArbre :: Ord a => [a] -> Arbre a
construireArbre [] = Nil
construireArbre (x:xs) = ajouterArbre x (construireArbre xs)

--construireArbre2 ::  [a]-> Arbre a 
--construireArbre2  = foldl ajouterArbre Nil 

--appartient :: a -> Arbre a -> Bool
--appartient x Nil = False
--appartient x (Noeud n g d) = if x == n then True
--                             else if x < n then appartient x g
--                                                else appartient x d

main = do
  args <- getArgs
  print $ show y
  print $ construireArbre $ map (read::String->Int) args
 where y =  Noeud 13 (Noeud 2 Nil (Noeud 12 Nil Nil))(Noeud 42 (Noeud 37 Nil Nil)(Noeud 51 Nil Nil))  
