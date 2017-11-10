import Network.Socket
import System.IO

main = withSocketsDo $ do
  let myPort = 3000
      myIp = tupleToHostAddress (127, 0, 0, 1)
  mySocket <- socket AF_INET Stream defaultProtocol 
  connect mySocket $ SockAddrInet myPort myIp
  myHandle <- socketToHandle mySocket ReadWriteMode
  handleServer myHandle

handleServer theHandle = do
  hPutStrLn theHandle "hello"
  hClose theHandle

