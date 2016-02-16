#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class Foo
{
public:
	Foo()
		: flag_(0)
		, thread1_(std::bind(&Foo::threadFunc1, this))
		, thread2_(std::bind(&Foo::threadFunc2, this))
	{
	}

	~Foo()
	{
		thread1_.join();
		thread2_.join();
	}

private:
	void threadFunc1()
	{
		{
			std::unique_lock<std::mutex> ul(mutex_);
			while (0 == flag_) {
				cond_.wait(ul); //线程1需要等到线程2将flag设置为非0才进行打印
			}
			std::cout << "threadFunc1: " << flag_ << std::endl;
		}
	}

	void threadFunc2()
	{
		// 为了测试，等待3秒
		std::this_thread::sleep_for((std::chrono::milliseconds(3000)));
		std::unique_lock<std::mutex> ul(mutex_);
		flag_ = 100;
		cond_.notify_one();
	}

	int flag_;
	std::mutex mutex_;
	std::condition_variable cond_;
	std::thread thread1_;
	std::thread thread2_;
};

int main()
{
	Foo f;

	system("pause");
	return 0;
}