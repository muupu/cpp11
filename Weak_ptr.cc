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
        // 在if中，oberve和weak共享对象
        std::cout << "observe() able to lock weak_ptr<>, value=" << *observe << "\n";
    } else {
        std::cout << "observe() unable to lock weak_ptr<>\n";
    }
}

// 由于指向的对象可能不存在，不能使用weak_ptr直接访问对象，必须调用lock()
// lock返回对象的shared_ptr
void weak_ptr_lock_example()
{
    std::cout << "--- weak_ptr_lock_example ---" << '\n';

    std::weak_ptr<int> weak;
    observe(weak); // observe() unable to lock weak_ptr<>
    {
        auto shared = std::make_shared<int>(42);
        weak = shared; // weak_ptr支持直接赋值
        std::cout << "weak_ptr<> initialized with shared_ptr.\n";
        observe(weak); // observe() able to lock weak_ptr<>, value=42
    } // shared_ptr<> has been destructed due to scope exit.
    observe(weak); // observe() unable to lock weak_ptr<>
}

int main () 
{
  weak_ptr_constructor_example();
  weak_ptr_constructor_example2();
  weak_ptr_lock_example();
  return 0;
}