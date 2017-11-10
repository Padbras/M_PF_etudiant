
multiples :: Int -> [(Int, Int)]
multiples n = [(x,y) | x <-[1..n], y<-[x..n], x*y==n]

tripletsPyth :: Int -> [(Int,Int,Int)]
tripletsPyth n = [(x,y,z) | x<-[1..n], y<-[x..n], z<-[y..n], (x*x)+(y*y) == (z*z)]

-- quicksort :: [Int] -> [Int]

main = do
    print $ [x | x<-[0,2..42]]
    print $ [x | x <-[0..42], even x]
    print $ [ if even x then x else -x | x <- [2..13]]
    print $ multiples 20
    print $ tripletsPyth 10
