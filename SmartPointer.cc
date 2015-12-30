
#include <iostream>
#include <memory>

void shared_ptr_constructor_example()
{
	std::shared_ptr<int> p1;
	std::shared_ptr<int> p2 (nullptr);

	std::cout << "use_count:\n";
  	std::cout << "p1: " << p1.use_count() << '\n';
  	std::cout << "p2: " << p2.use_count() << '\n';
}

int main()
{
	shared_ptr_constructor_example();
	return 0;
}