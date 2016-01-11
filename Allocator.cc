#include <memory>

using namespace std;

int main()
{
	allocator<string> alloc;
	auto const p = alloc.allocate(n); // 分配n个未初始化的string
	
}