data Peutetre = Rien | Juste Float

instance Show Peutetre where
  show Rien = "rien"
  show (Juste x) = show x

racine :: Float -> Peutetre
racine x = if x<0 then Rien else (Juste(sqrt x))

peutetreFois2 :: Peutetre -> Peutetre
peutetreFois2 Rien = Rien
peutetreFois2(Juste x) = Juste(x*2)


main = do
  print $map(peutetreFois2.racine) [-4..4]
