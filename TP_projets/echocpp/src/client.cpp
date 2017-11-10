#include <arpa/inet.h>
#include <cstring>
#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

const int PORT = 3000;
const int BUFFER_SIZE = 1024;

int main() {
  struct sockaddr_in myServerAddr;
  myServerAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  myServerAddr.sin_family = AF_INET;
  myServerAddr.sin_port = htons(PORT);

  int mySocket = socket(AF_INET, SOCK_STREAM, 0);
  connect(mySocket, (struct sockaddr *)&myServerAddr, sizeof(myServerAddr));

  string myLocalMsg = "hello";
  send(mySocket, myLocalMsg.data(), myLocalMsg.size(), 0);
  close(mySocket);

  return 0;
}

