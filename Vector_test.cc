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
		it = vecPtr.erase(it); // 使用erase后迭代器已经失效，需要用erase的返回值给迭代器重新赋值
	}
}

void test_pointer()
{
	autonavi::vector<char*> vecPtr;
	char* ptr = new char[16];
	ptr[0] = 0;
	memcpy(ptr, "abc", 16);
	char* ptr2 = new char[16];
	ptr2[0] = 0;
	memcpy(ptr2, "abc", 16);
	vecPtr.push_back(ptr);
	vecPtr.push_back(ptr2);
	autonavi::vector<char*>::iterator it = vecPtr.begin();
	for (; it != vecPtr.end();)
	{
		delete[] * it;
		it = vecPtr.erase(it);
	}
}

int main()
{
	test_object();
	test_pointer();
	return 0;
}