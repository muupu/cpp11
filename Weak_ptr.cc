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

void observe(std::weak_ptr<int> weak) 
{
    if (auto observe = weak.lock()) {
        std::cout << "\tobserve() able to lock weak_ptr<>, value=" << *observe << "\n";
    } else {
        std::cout << "\tobserve() unable to lock weak_ptr<>\n";
    }
}


void weak_ptr_lock_example()
{
    std::cout << "--- weak_ptr_lock_example ---" << '\n';

    std::weak_ptr<int> weak;
    observe(weak);
    {
        auto shared = std::make_shared<int>(42);
        weak = shared;
        std::cout << "weak_ptr<> initialized with shared_ptr.\n";
        observe(weak);
    }
    observe(weak);
}

int main () 
{
  weak_ptr_constructor_example();
  weak_ptr_constructor_example2();
  weak_ptr_lock_example();
  return 0;
}