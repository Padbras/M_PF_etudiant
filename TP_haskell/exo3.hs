import System.Environment

main = do
    args <- getArgs
    print(zip args [1..])
  
