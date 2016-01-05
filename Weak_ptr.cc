#include <iostream>
#include <memory>

using namespace std;

struct Foo
{
    int* data;
};

void weak_ptr_constructor_example()
{
    std::cout << "--- weak_ptr_constructor_example ---" << '\n';

    std::shared_ptr<int> sp (new int);

    std::weak_ptr<int> wp1;
    std::weak_ptr<int> wp2 (wp1);
    std::weak_ptr<int> wp3 (sp);

    std::cout << "use_count:\n";
    std::cout << "wp1.use_count: " << wp1.use_count() << '\n'; // 0
    std::cout << "wp2.use_count: " << wp2.use_count() << '\n'; // 0
    std::cout << "wp3.use_count: " << wp3.use_count() << '\n'; // 1
}

void weak_ptr_constructor_example2()
{
    std::cout << "--- weak_ptr_constructor_example2 ---" << '\n';

    std::weak_ptr<Foo> w_ptr;
   {
      auto ptr = std::make_shared<Foo>();
      w_ptr = ptr; // 赋值后共享一个对象
      std::cout << "w_ptr.use_count() inside scope: " << w_ptr.use_count() << '\n'; // 1
   }
 
   std::cout << "w_ptr.use_count() out of scope: " << w_ptr.use_count() << '\n'; // 0
   std::cout << "w_ptr.expired() out of scope: " << std::boolalpha << w_ptr.expired() << '\n'; // true
}

int main () 
{
  weak_ptr_constructor_example();
  weak_ptr_constructor_example2();
  return 0;
}