#include <iostream>
#include <memory>

using namespace std;

struct C 
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
    std::cout << "wp1.use_count: " << wp1.use_count() << '\n';
    std::cout << "wp2.use_count: " << wp2.use_count() << '\n';
    std::cout << "wp3.use_count: " << wp3.use_count() << '\n';
}

int main () 
{
  weak_ptr_constructor_example();
  return 0;
}