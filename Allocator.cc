#include <memory>

using namespace std;

int main()
{
	allocator<string> alloc;
	auto const p = alloc.allocate(n); // 分配n个未初始化的string

	// allocator分配未构造的内存
	auto q = p;
	alloc.construct(q++);
	alloc.construct(q++, 10, 'c');
	alloc.construct(q++, "hi");
}