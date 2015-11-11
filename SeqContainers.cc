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

    // 添加元素用光多余容量
	while (ivec.size() != ivec.capacity())
		ivec.push_back(0);
	cout << "ivec: size: " << ivec.size()
	<< " capacity: "  << ivec.capacity() << endl;

	// 再添加一个元素，vector会重新分配内存空间
	ivec.push_back(42);
	// size为51，capacity会大于等于51
	cout << "ivec: size: " << ivec.size()
		 << " capacity: "  << ivec.capacity() << endl;

    // 将超出当前大小的多余内存退回给系统
	ivec.shrink_to_fit();
	// size不会改变，capacity的改变依赖于具体实现
	// shrink_to_fit只是一个请求，不保证一定退还内存
	cout << "ivec: size: " << ivec.size()
	<< " capacity: "  << ivec.capacity() << endl;
}

void moreStringOperations
{
	const char *cp = "Hello world";
	char noNull[] = {'H', 'i'};
	string s1(cp);        // 构造string：直到遇到空字符
	string s2(noNull, 2); // 从noNull拷贝两个字符
	// string s3(noNull);    // 错误
	string s4(cp + 6, 5); // 从cp[6]开始拷贝5个字符
	string s5(s1, 6, 5);  // 从s1[6]开始拷贝5个字符
	string s6(s1, 6);     // 从s1[6]开始拷贝，直到s1末尾
	string s7(s1, 6, 20); // 正确：只会拷贝到s1末尾
	// string s8(s1, 16);    // 抛出一个out_of_range异常

	string s("hello world");
	string s12 = s.substr(0, 5);
	string s13 = s.substr(6);
	string s14 = s.substr(6, 11);
	string s15 = s.substr(12);  // 抛出一个out_of_range异常

	s.insert(s.size(), 5, '!');
	s.erase(s.size() - 5, 5); //删除s最后5个字符

	s.assign(cp, 7);
	s.insert(s.size(), cp + 7);

	s.append(" C++");
	s.insert(s.size(), " C++");
	s.replace(5, 3, "CPP");
	s.replace(5, 3, "CPP11");
}

void stringSearch()
{
	// find
	// 返回的是string::size_type，是个unsigned类型
	// 若搜索失败，返回一个string::npos的static成员
	string name("AnnaBelle");
	auto pos1 = name.find("Anna"); // pos1 == 0

	// find是大小写敏感的
	string lowercase("annabelle");
	pos1 = lowercase.find("Anna"); // pos1 == npos

	// 查找与给定字符串中任何一个字符匹配的位置
	string numbers("0123456789"), name("r2d2");
	auto pos = name.find_first_of(numbers);

	// 搜索第一个不在参数中的字符
	strign dept("03714p3");
	auto pos = dept.find_first_not_of(numbers);

	// 指定在哪里开始搜索
	string::size_type pos = 0;
	while ((pos = name.find_first_of(numbers, pos)) != string::npos)
	{
		cout << "found number at index: " << pos
		     << " element is " << name[pos] << endl;
		++pos;
	}

	// rfind
	string river("Mississippi");
	auto first_pos = river.find("is");
	auto last_pos = river.rfind("is");
}

void stringNumConv()
{
	int i = 42;
	string s = to_string(i);
	double d = stod(s);

	// 要转换为数值的string中，第一个非空白字符必须是数值中可能出现的字符
	string s2 = "pi = 3.14";
	d = stod(s2.substr(s2.find_first_of("+-.0123456789")));
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
