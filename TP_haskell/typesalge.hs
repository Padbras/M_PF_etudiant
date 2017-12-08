data Jour = Lundi | Mardi | Mercredi| Jeudi| Vendredi| Samedi| Dimanche

estWeekend :: Jour -> Bool
estWeekend Samedi = True
estWeekend Dimanche = True
estWeekend _ = False

compterOuvrables :: [Jour] -> Int
compterOuvrables [] = 0
compterOuvrables (x:xs) = if (estWeekend x) == False then 1+compterOuvrables xs
                          else compterOuvrables xs

main = do
  print (estWeekend (Samedi) )
  print (compterOuvrables [Lundi,Mardi, Samedi, Dimanche, Mercredi])
