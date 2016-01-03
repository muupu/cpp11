
#include <iostream>
#include <memory>

using namespace std;

void unique_ptr_constructor_example()
{
	std::default_delete<int> d;
	std::unique_ptr<int> u1;  // u1: null
	std::unique_ptr<int> u2 (nullptr); // u2: null
	std::unique_ptr<int> u3 (new int); // u3: not null
	std::unique_ptr<int> u4 (new int, d); // u4: not null
	std::unique_ptr<int> u5 (new int, std::default_delete<int>()); // u5: null...why?
	std::unique_ptr<int> u6 (std::move(u5)); // u6: null
	std::unique_ptr<int> u7 (std::move(u6)); // u7: not null
	std::unique_ptr<int> u8 (std::auto_ptr<int>(new int)); // u8: not null

	std::cout << "u1: " << (u1?"not null":"null") << '\n'; 
	std::cout << "u2: " << (u2?"not null":"null") << '\n'; 
	std::cout << "u3: " << (u3?"not null":"null") << '\n'; 
	std::cout << "u4: " << (u4?"not null":"null") << '\n'; 
	std::cout << "u5: " << (u5?"not null":"null") << '\n';
	std::cout << "u6: " << (u6?"not null":"null") << '\n';
	std::cout << "u7: " << (u7?"not null":"null") << '\n';
	std::cout << "u8: " << (u8?"not null":"null") << '\n';
}

void unique_ptr_release_example()
{
	std::unique_ptr<int> auto_pointer(new int);
	int * manual_pointer;

	*auto_pointer=10;

	manual_pointer = auto_pointer.release();
	// (auto_pointer is now empty)

	std::cout << "manual_pointer points to " << *manual_pointer << '\n';

	delete manual_pointer;
}

void unique_ptr_no_copy_assign()
{
	unique_ptr<string>p1(new string("Stegosaurus"));
	// unique_ptr<string> p2(p1);  // error: no copy for unique_ptr
	// unique_ptr<string> p3;
	// p3 = p2;  // error: no assign for unique_ptr

	// 虽然不能拷贝或赋值unique_ptr，但可以通过release和reset将指针的所有权
	// 从一个(非const)unique_ptr转移给另一个unique
	// transfers ownership from p1 (which points to the string Stegosaurus) to p2
	unique_ptr<string> p2(p1.release()); // release makes p1 null
	unique_ptr<string> p3(new string("Trex"));
	// transfers ownership from p3 to p2
	p2.reset(p3.release()); // reset deletes the memory to which p2 had pointed
}

int main () 
{
	unique_ptr_constructor_example();
	unique_ptr_release_example();
	unique_ptr_no_copy_assign();
	return 0;
}