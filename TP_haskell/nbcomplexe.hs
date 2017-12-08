type Complexe  = (Float,Float)


modComp :: Complexe -> Float
modComp (r,i)  = sqrt ( r**2 + i**2)

conjComp :: Complexe -> Complexe
conjComp (r,i) = (r,(-i))

addComp :: Complexe -> Complexe -> Complexe
addComp  (a,b) (c,d) = (a+c, b+d)

main = do
  print $ modComp (2,3)
  print $ conjComp (3,4)
  print $ addComp (1,2) (3,4)
