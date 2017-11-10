import Control.Concurrent
import Control.Monad
import Network.Socket
import System.IO

main = withSocketsDo $ do
  let port = 3000
  myListenSocket <- socket AF_INET Stream defaultProtocol 
  bind myListenSocket $ SockAddrInet port iNADDR_ANY
  listen myListenSocket 2
  putStrLn $ "server running on port " ++ (show port) ++ "..."
  runServer myListenSocket

runServer theListenSocket = forever $ do
  (mySocket, _) <- accept theListenSocket
  forkIO $ do
    myHandle <- socketToHandle mySocket ReadWriteMode
    handleClient myHandle

handleClient theHandle = do
  myMsg <- hGetLine theHandle 
  putStrLn myMsg
  hClose theHandle

