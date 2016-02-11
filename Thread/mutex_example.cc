#include <thread>
#include <iostream>
#include <vector>
#include <mutex>
struct Counter {
    std::mutex mutex;
    int value;
    Counter() : value(0) {}
    void increment(){
       // mutex.lock();                //【1】表示没有使用锁
        ++value;
       // mutex.unlock();              //【1】
    }
    void decrement(){
        mutex.lock();
        --value;
        mutex.unlock();
    }
};
int main(){
    Counter counter;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread([&](){
            for(int i = 0; i < 10000; ++i){
                counter.increment();
            }
        }));
    }
    for(auto& thread : threads){
        thread.join();
    }
    std::cout << counter.value << std::endl;
    return 0;
}