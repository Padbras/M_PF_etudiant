#include <arpa/inet.h>
#include <iostream>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

using namespace std;

const int PORT = 3000;
const int BUFFER_SIZE = 1024;

void handleClient(int theSocket) {
  char buffer[BUFFER_SIZE];
  int readSize = recv(theSocket, buffer, BUFFER_SIZE, 0);
  if (readSize > 0) {
    cout << buffer << endl;
  }
  close(theSocket);
}

int main() {
  struct sockaddr_in myServerAddr;
  myServerAddr.sin_family = AF_INET;
  myServerAddr.sin_addr.s_addr = INADDR_ANY;
  myServerAddr.sin_port = htons(PORT);

  int myListenSocket = socket(AF_INET , SOCK_STREAM , 0);
  bind(myListenSocket, (struct sockaddr *)&myServerAddr, sizeof(myServerAddr));
  listen(myListenSocket, 2);
  cout << "running server on port " << PORT << "..." << endl;

  struct sockaddr_in myClientAddr;
  int myClientAddrLen = sizeof(struct sockaddr_in);
  int mySocket = accept(myListenSocket, (struct sockaddr *)&myClientAddr, 
      (socklen_t*)&myClientAddrLen);
  thread myThread(handleClient, mySocket);  
  myThread.detach();

  sleep(1);  // to be removed

  return 0;
}

