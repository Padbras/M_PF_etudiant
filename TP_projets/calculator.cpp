// g++ -std=c++14 -Wall -Wextra -o calculator calculator.cpp

#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {

  while (true) {
    cout << "Entrez une expression: " << endl;
    string str;
    getline(cin, str);

    if (str.empty())
      break;

    istringstream iss(str);
    vector<string> tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};

    for (const auto & t : tokens)
      cout << t << endl;
  }

  return 0;
}

