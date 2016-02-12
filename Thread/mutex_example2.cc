#include <iostream>
#include <stdlib.h>
#include <thread>
#include <string>
#include <mutex>

int g_num = 0;
std::mutex g_mutex;

void thread1()
{
	//g_mutex.lock();
	g_num = 10;
	for (int i=0; i<10; i++){
		std::cout << "thread1:" << g_num << std::endl; // std::cout不是线程安全的
	}
	//g_mutex.unlock();
}

void thread2()
{
	//std::lock_guard<std::mutex> lg(g_mutex);
	g_num = 20;
	for (int i=0; i<10; i++){
		std::cout << "thread2:" << g_num << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::thread t1(thread1);
	std::thread t2(thread2);
	t1.join();
	t2.join();
	
	return 0;
}