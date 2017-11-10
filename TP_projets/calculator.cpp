// g++ -std=c++14 -Wall -Wextra -o calculator calculator.cpp

#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Expr {
  virtual int eval() const = 0;
  virtual ~Expr() = default;
};

using expr_t = unique_ptr<Expr>;

struct ExprAdd : Expr {
  expr_t _e1, _e2;
  int eval() const override {
    // TODO
    return 0;
  }
  ExprAdd(expr_t & e1, expr_t & e2) : _e1(move(e1)), _e2(move(e2)) {}
};

struct ExprMul : Expr {
  expr_t _e1, _e2;
  int eval() const override {
    // TODO
    return 0;
  }
  ExprMul(expr_t & e1, expr_t & e2) : _e1(move(e1)), _e2(move(e2)) {}
};

struct ExprVal : Expr {
  int _v;
  int eval() const override {
    // TODO
    return 0;
  }
  ExprVal(int v) : _v(v) {}
};

using tok_vec_t = vector<string>;
using tok_iter_t = tok_vec_t::const_iterator;
using tok_res_t = pair<expr_t, tok_iter_t>;

tok_res_t parse(tok_iter_t iter) {
  if (*iter == "+") {
    // TODO
    return {make_unique<ExprVal>(0), iter};
  }
  else if (*iter == "*") {
    // TODO
    return {make_unique<ExprVal>(0), iter};
  }
  else {
    expr_t e = make_unique<ExprVal>(stoi(*iter));
    return {move(e), ++iter};
  }
}

int main() {

  while (true) {
    cout << "Enter expression: " << endl;
    string str;
    getline(cin, str);

    if (str.empty())
      break;

    istringstream iss(str);
    tok_vec_t tokens{istream_iterator<string>{iss}, istream_iterator<string>{}};
    tok_res_t parseRes = parse(tokens.begin());

    int evalRes = parseRes.first->eval();
    cout << evalRes << endl;
  }

  return 0;
}

