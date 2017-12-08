
data Arbre a = Nil
                 | Noeud a (Arbre a) (Arbre a)

instance Eq Angle where
  (==) (Radian d) (Radian e) = d == e 
  (==) (Degre d) (Degre e) = d ==  e
  (==) a1  a2 = a1 == (convert a2)

convert :: Angle -> Angle
convert (Degre a) =  (Radian $  a*(pi/180.0))
convert (Radian a) = (Degre $ a*(180.0/pi))

-- recupValeur :: Angle -> Float
-- recupValeur Degre a = a
-- recupValeur Radian a = a 

x::Angle
x = Radian pi
w = Radian pi
y = Degre 180

main = do
  print $  x == w
  print $ convert (Degre 90)
  print $ convert (Radian pi)

