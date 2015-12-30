#include <iostream>     // std::cout
#include <functional>   // std::bind
#include <string>       // std::string

using namespace std::placeholders;    // adds visibility of _1, _2, _3,...

// a function: (also works with function object: std::divides<double> my_divide;)
double my_divide (double x, double y) {return x/y;}

struct MyPair {
  double a,b;
  double multiply() {return a*b;}
};

void bind_example1(){
  
  // binding functions:
  auto fn_five = std::bind (my_divide, 10, 2);               // returns 10/2
  std::cout << fn_five() << '\n';                           // 5

  // 2 使用_1
  auto fn_half = std::bind(my_divide, _1, 2);       // returns x/2
  std::cout << fn_half(10) << '\n';                  // 5

  auto fn_invert = std::bind(my_divide,_2,_1);            // returns y/x
  std::cout << fn_invert(10,2) << '\n';                    // 2/10 = 0.2

  auto fn_rounding = std::bind<int> (my_divide,_1,_2);     // returns int(x/y)
  std::cout << fn_rounding(10,3) << '\n';                  // 3

  MyPair ten_two {10,2};
  // binding members:
  auto bound_member_fn = std::bind (&MyPair::multiply,_1); // returns x.multiply()
  std::cout << bound_member_fn(ten_two) << '\n';           // 20

  auto bound_member_data = std::bind (&MyPair::a,ten_two); // returns ten_two.a
  std::cout << bound_member_data() << '\n';                // 10
}

//将check_size改造成，接受单一参数
bool check_size(const std::string &s, std::string::size_type sz)
{
  return s.size() >= sz;
}

void bind_check_size()
{
  auto check6 = std::bind(check_size, _1, 6); // check6现在只接受单一参数，sz参数绑定为6
  std::string s = "hello";
  bool b1 = check6(s);  // 即调用check(s, 6)
  std::cout << b1 << '\n';
}

int main () {
  bind_example1();
  bind_check_size();
  return 0;
}