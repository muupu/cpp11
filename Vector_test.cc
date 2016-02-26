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
	std::vector<TestClass> vecPtr;
	TestClass test1;
	TestClass test2;
	TestClass test3;
	vecPtr.push_back(test1);
	vecPtr.push_back(test2);
	vecPtr.push_back(test3);
	std::vector<TestClass>::iterator it = vecPtr.begin();
	for (; it != vecPtr.end();)
	{
		// vecPtr.erase(it++); // 错误的使用erase方法
		it = vecPtr.erase(it); // 使用erase后迭代器已经失效，需要用erase的返回值给迭代器重新赋值
	}
}

void test_pointer()
{
	std::vector<char*> vecPtr;
	char* ptr = new char[16];
	ptr[0] = 0;
	memcpy(ptr, "abc", 16);
	char* ptr2 = new char[16];
	ptr2[0] = 0;
	memcpy(ptr2, "abc", 16);
	vecPtr.push_back(ptr);
	vecPtr.push_back(ptr2);
	std::vector<char*>::iterator it = vecPtr.begin();
	for (; it != vecPtr.end();)
	{
		delete[] * it;
		it = vecPtr.erase(it);
	}
}

void test_pointer2()
{
	std::vector<TestClass*> vecPtr;
	TestClass *a = new TestClass;
	TestClass *b = new TestClass;
	TestClass *c = new TestClass;
	vecPtr.push_back(a);
	vecPtr.push_back(b);
	vecPtr.push_back(c);
	std::vector<TestClass*>::iterator it = vecPtr.begin();
	for (; it != vecPtr.end();)
	{
		//vecPtr.erase(it++);
		delete *it;
		*it = NULL;
		it = vecPtr.erase(it);
		
	}
}

void test_pointer3()
{
	std::vector<TestClass*> vecPtr;
	TestClass *a = new TestClass;
	TestClass *b = new TestClass;
	TestClass *c = new TestClass;
	vecPtr.push_back(a);
	vecPtr.push_back(b);
	vecPtr.push_back(c);
	std::vector<TestClass*>::iterator it = vecPtr.begin();
	for (; it != vecPtr.end(); it++)
	{
        if (*it != NULL)
        {
            delete *it;
		    *it = NULL;
		    //it = vecPtr.erase(it);
		    //vecPtr.erase(it++);
        }
	}
	vecPtr.clear();
}

void test_pointer4()
{
	std::vector<TestClass*> vecPtr;
	TestClass *a = new TestClass;
	TestClass *b = new TestClass;
	TestClass *c = new TestClass;
	vecPtr.push_back(a);
	vecPtr.push_back(b);
	vecPtr.push_back(c);
	std::vector<TestClass*>::iterator it = vecPtr.begin();
	for (; it != vecPtr.end(); it++)
	{
		if (*it != NULL)
		{
			delete *it;
			*it = NULL;
		}
		
		//vecPtr.erase(it++);
	}
	vecPtr.clear();
}

void test_pointer5()
{
	TestClass *a = new TestClass;
	TestClass *b = new TestClass(*a);
	TestClass *c = new TestClass(*a);

	printf("----------/n");

	std::vector<TestClass*> vec;
	//vec.reserve(3);
	vec.push_back(a);
	vec.push_back(b);
	vec.push_back(c);

	std::vector<TestClass*>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		delete *iter;   //*iter = a , b, c  
	}

	vec.clear();
}

int main()
{
	test_object();
	test_pointer();
	test_pointer2();
	test_pointer3();
	test_pointer4();
	test_pointer5();
	return 0;
}