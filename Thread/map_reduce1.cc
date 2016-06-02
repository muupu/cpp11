#include <iostream>
#include <vector>
#include <future>
using namespace std;

long long func(int n)
{
    long long ret=1;
    for (int i = 1; i <= n; i++)
    {
        ret *= i;
    }
    return ret;

}

int main()
{
    vector<int> data = {9, 11, 13, 17, 19};
    vector<future<long long>> fus; // std::future 提供了一个访问异步操作结果的机制
    for (auto i : data)
    {
        packaged_task<long long() > pt(bind(func,i)); // packaged_task包装一个异步操作
        fus.push_back(std::move(pt.get_future()));
        std::thread(std::move(pt)).detach();
    }
    for(auto& i:fus)
    {
        i.wait(); // 通过future.get/wait来获取这个未来的结果
        cout<<i.get()<<endl;
    }
    return 0;
}