
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

	// 解引用shared_ptr
	std::cout << "*foo: " << *foo << '\n';   // *foo: 10
	std::cout << "*bar: " << *bar << '\n';   // *bar: 20
	std::cout << "*baz: " << baz->first << ' ' << baz->second << '\n'; // *baz: 30 40
}

void shared_ptr_copy_assign_example()
{
	auto p = std::make_shared<int>(42); // p所指向的对象(make_shared<int>(42))只有一个引用者(p)
	std::cout << "p.use_count(): " << p.use_count() << '\n';
	auto q(p); // 现在(make_shared<int>(42))有两个引用者(p，q)
	std::cout << "p.use_count(): " << p.use_count() << '\n';
	std::cout << "q.use_count(): " << q.use_count() << '\n';

	auto r = std::make_shared<int>(10);
	std::cout << "r.use_count(): " << r.use_count() << '\n';
	r = q;
	std::cout << "r.use_count(): " << r.use_count() << '\n';
	std::cout << "q.use_count(): " << q.use_count() << '\n';
}

int main()
{
	shared_ptr_constructor_example();
	make_shared_example();
	shared_ptr_copy_assign_example();
	return 0;
}