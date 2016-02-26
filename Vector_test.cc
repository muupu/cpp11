#include <string>
#include <vector>

class TestClass
{
public:
	TestClass()
	{
		printf("A()\n");
	}

	~TestClass()
	{
		printf("~A()\n");
	}

	TestClass(const TestClass& other)
	{
		printf("other\n");

	}

};

void test_object()
{
	autonavi::vector<TestClass> vecPtr;
	TestClass test1;
	TestClass test2;
	TestClass test3;
	vecPtr.push_back(test1);
	vecPtr.push_back(test2);
	vecPtr.push_back(test3);
	autonavi::vector<TestClass>::iterator it = vecPtr.begin();
	for (; it != vecPtr.end();)
	{
		// vecPtr.erase(it++); // 错误的使用erase方法
		it = vecPtr.erase(it);
	}
}

int main()
{
	test_object();
	return 0;
}