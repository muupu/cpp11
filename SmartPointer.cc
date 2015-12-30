
#include <iostream>
#include <memory>

void shared_ptr_constructor_example()
{
	std::shared_ptr<int> p1;
	std::shared_ptr<int> p2 (nullptr);
	std::shared_ptr<int> p3 (new int);

	std::cout << "use_count:\n";
  	std::cout << "p1: " << p1.use_count() << '\n';
  	std::cout << "p2: " << p2.use_count() << '\n';
  	std::cout << "p3: " << p3.use_count() << '\n';
}

// 动态分配对象的内存并初始化，返回指向此对象的shared_ptr
void make_shared_example()
{
	// 指向一个值为10的int类型的shared_ptr
	std::shared_ptr<int> foo = std::make_shared<int> (10);

	// same as:
  	std::shared_ptr<int> foo2 (new int(10));

  	// 使用auto
  	auto bar = std::make_shared<int> (20);
	auto baz = std::make_shared<std::pair<int,int>> (30,40);

	std::cout << "*foo: " << *foo << '\n';
	std::cout << "*bar: " << *bar << '\n';
	std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n'
}

int main()
{
	shared_ptr_constructor_example();
	make_shared_example();
	return 0;
}