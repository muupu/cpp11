#include <list>
#include <string>
#include <deque>
#include <forward_list>
#include <array>
#include <utility> // std::swap

using namespace std;

// swap用来交换两个相同类型容器的内容
void usingswap()
{
	vector<string> svec1(10);  // 10个元素
	vector<string> svec2(24);  // 24个元素
	swap(svec1, svec2);        // 交换操作很快（除了array）,swap并未交换元素本身
	                           // 只是交换了两个容器的内部数据结构

	// swap例子 
	int x=10, y=20;                  // x:10 y:20
	swap(x,y);                  // x:20 y:10

	int foo[4];                      // foo: ?  ?  ?  ?
	int bar[] = {10,20,30,40};       // foo: ?  ?  ?  ?    bar: 10 20 30 40
	swap(foo,bar);              // foo: 10 20 30 40   bar: ?  ?  ?  ?

	cout << "foo contains:";
	for (int i: foo) cout << ' ' << i;
	cout << '\n';
}

void relationalOperators()
{
	vector<int> v1 = { 1, 3, 5, 7, 9, 12 };
	vector<int> v2 = { 1, 3, 9 };
	vector<int> v3 = { 1, 3, 5, 7 };
	vector<int> v4 = { 1, 3, 5, 7, 9, 12 };

	v1 < v2;  // true：在[2]处不相等，且v1[2]小于等于v2[2]
	v1 < v3;  // false
	v1 == v4; // true：容器大小相等，且每个元素都相等
	v1 == v2; // false

	// 这种比较需要其元素定义了相应的比较运算符
	// vector<Sales_data> storeA, storeB;
	// if (storeA < storeB) // 错误：Sales_data没有定义<运算符
}

void capacity()
{
	vector<int> ivec;
	cout << "ivec: size: " << ivec.size()     // 已经保存的元素的数目
	     << "capacity: "   << ivec.capacity() // 不重新分配内存空间的话，最多可以保存多少个元素
	     << endl;

	for (vector<int>::size_type ix = 0; ix != 24; ++ix)
		ivec.push_back(ix);
	// 添加24个元素后，size为24；capacity会大于等于24
	cout << "ivec: size: " << ivec.size()
		 << " capacity: "  << ivec.capacity() << endl;

	// 预分配一些额外空间
    ivec.reserve(50);
    // size为24，capacity会大于等于50
    cout << "ivec: size: " << ivec.size()
		 << " capacity: "  << ivec.capacity() << endl;
}

int main()
{
	list<string> authors = {"Milton", "Shakespeare", "Austen"};
	vector<const char*> articles = {"a", "an", "the"};

	// 将一个容器(list2)初始化为另一个容器(authors)的拷贝
	// 两个容器的容器类型和元素类型都要相同！
	list<string> list2(authors);     // 类型匹配
	deque<string> authList(authors); // 错误：容器类型不匹配
	vector<string> words(articles);  // 错误：容器类型必须匹配
    // 正确：可以将const char*元素转换为string
	forward_list<string> words(articles.begin(), articles.end());

	auto it1 = authors.begin(); 
	auto it2 = authors.rbegin();  // 返回反向迭代器
	auto it3 = authors.cbegin();  // 返回const迭代器
	auto it4 = authors.crbegin(); 

	// 与顺序容器大小相关的构造函数
	vector<int> ivec(10, -1);     // 10个-1
	list<string> svec(10, "hi!")  // 10个string
	forward_list<int> ivec2(10);  // 10个0
	deque<string> svec2(10);      // 10个空string

	// 当定义标准库array，要指定容器的大小
	array<int, 42> a1;
	array<string, 10> a2;
	// 为了使用array类型，还要同时指定元素类型
	array<int ,10>::size_type i;  // 正确
	arrar<int>::size_type j;      // 错误：没有指定大小

    // array初始化
    array<int, 10> ia1;  // 10个默认初始化的int
    array<int ,10> ia2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  // 列表初始化
    array<int, 10> ia3 = {42};  // ia3[0]为42, 剩余元素为0（进行了值初始化）

    // array支持拷贝和对象赋值操作
    // int digs[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // int cpy[10] = digs;  // 错误：内置数组不支持拷贝或赋值
    array<int, 10> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    array<int, 10> copy = digits;  // 正确：只要数组类型匹配即合法

    // 容器赋值运算：assign操作
    // assign允许我们从过一个不同但相容的类型赋值，或者从容器的一个子序列赋值
    list<string> names;
    vector<const char*> oldstyle;
    // names = oldstyle;  // 错误：容器类型不匹配
    names.assign(oldstyle.cbegin, oldstyle.cend()); // 正确：可以将const char* 转换为string

    // assign第二个版本
    list<string> slist1(1);   // 1个元素，为空string
    slist1.assign(10, "Hiya"); // 替换容器中原有的元素：10个元素，每个都是"Hiya"


	return 0;
}
