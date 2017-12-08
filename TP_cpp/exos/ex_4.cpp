#include <algorithm>
#include <functional>
#include <iostream>

using namespace std::placeholders;

int main()
{

  std::vector<int> v {1,-2,3};
  std::vector<int> v_copy;

  std::copy_if(v.begin(), v.end(), back_inserter(v_copy),[](int x){return x > 0;});

  for(int & i : v_copy)
    std::cout << v_copy[i] << ' ';

  return 0;
}
