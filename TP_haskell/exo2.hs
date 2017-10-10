import Control.Monad
import System.Exit

main = forever looping

looping = do
          putStrLn "Entrez votre nom svp : "
          nom <- getLine
          if nom == "quit" then exitSuccess else  putStrLn ("Bonjour " ++ nom ++ " ! Comment ça va la famille?")
         
