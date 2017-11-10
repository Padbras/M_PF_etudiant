import System.Environment

formatMessage :: Integer -> String
formatMessage args
	| l < (-20) = "frisquet"
	| l >= 20 = "canicule"
	| otherwise = "nirvana"
	where l = args

analyseTemp :: Integer -> String
analyseTemp x = if x < (-20)
                then ("Frisquet")
                else if x >= 20 
	        then ("canicule")
                else ("nirvana")



main = do
 print $ formatMessage 21
 print $ analyseTemp (15)


