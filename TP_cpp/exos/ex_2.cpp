#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

void versionimperative(std::vector<int> v)
{
  for(int i = 0; i<v.size(); i++)
    std::cout << v[i]+42 << ' ';
  std::cout << std::endl;
}


int main()
{
  std::vector<int> liste1 {1,2,3};
  std::for_each(liste1.begin(), liste1.end(), [](int n){std::cout << n+42 <<' ';});
  versionimperative(liste1);
  return 0;
}
