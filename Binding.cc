#include <iostream>     // std::cout
#include <functional>   // std::bind

// a function: (also works with function object: std::divides<double> my_divide;)
double my_divide (double x, double y) {return x/y;}

struct MyPair {
  double a,b;
  double multiply() {return a*b;}
};

int main () {
  using namespace std::placeholders;    // adds visibility of _1, _2, _3,...

  // binding functions:
  auto fn_five = std::bind (my_divide, 10, 2);               // returns 10/2
  std::cout << fn_five() << '\n';                           // 5

  // 2 使用_1
  auto fn_half = std::bind(my_divide, _1, 2);       // returns x/2
  std::cout << fn_half(10) << '\n';                  // 5

  return 0;
}