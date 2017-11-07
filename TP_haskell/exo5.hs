l1 = [37.. 42]

main = do
  print l1
  print(length l1)
  print(take 3 l1)
  print(drop 3 l1)
  print((take 3 l1, drop 3 l1))

--------------------------------


--    second xs = head (tail xs)  	
--		second::[xs] -> xs
--    swap (x, y) = (y, x) 
--		swap::(x,y) -> (y,x)
--    pair x y = (x, y) 
--		pair::x -> y -> (x,y)
--    double x = x*2 
--		double::Num x => x->x
--    palindrome xs = reverse xs == xs 
--		palindrome::Eq xs =>[xs]-> Bool
--    twice f x = f (f x) 
--		twice:: (x -> x) -> x -> x


-------------------------------
