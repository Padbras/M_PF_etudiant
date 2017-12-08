data Figure = Carre Float
  | Rectangle Float Float
  | Cercle Float

showFigure ::  Figure  -> String
showFigure (Carre c) = "Carre de cote " ++ show c
showFigure (Rectangle l h) = "Rectangle de largeur " ++ show l ++ " et de hauteur " ++ show h
showFigure (Cercle r) = "Disque de rayon " ++ show r

calculerAire :: Figure -> Float
calculerAire (Carre c ) = c*c
calculerAire (Rectangle l h) = l*h
calculerAire (Cercle c) = 2*c*pi
main = do
  print $ showFigure(Cercle 3)
  print $ calculerAire(Rectangle 3 4)
  print $ calculerAire(Cercle 3)
  
