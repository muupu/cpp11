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

	// 还未构造对象的情况下使用原始内存是错误的
	cout << *p << endl;    // 正确：使用string的输出运算符
	// cout << *q << endl; // 错误：q指向未构造函数

	while (q != p) {
		alloc.destroy(--q);
	}

	alloc.deallocate(p, n); // 通过deallocate释放内存给系统

	// 拷贝和填充未初始化内存的算法
	auto p = alloc.allocate(vi.size() * 2);
	auto q = uninitialized_copy(vi.begin(), vi.end(), p);
	
}