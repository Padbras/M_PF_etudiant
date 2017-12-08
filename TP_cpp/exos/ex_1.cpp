#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;
int fonction(int x, int y)
{
  return x+y;
}


int main()
{
  std::cout << fonction(2,3) << std::endl;
  std::function<int(int,int)> lambda = [](int x, int y){return x+y;};
  std::cout << lambda(40,2) << std::endl;
  std::function<int(int,int)> objetfonction = fonction; // Ou bien plus<int>
  std::cout << objetfonction(66,600) << std::endl;
  std::function<int(int)> fonctionpartielle = std::bind(fonction, 42, _1);
  std::cout << fonctionpartielle(1337) << std::endl;
  return 0;
}
