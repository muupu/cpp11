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
    vector<int> data = {9,11,13,17,19};
    vector<future<long long>> fus;
    for (auto i:data)
    {
    	fus.push_back(std::async(func,i));
    }
    for(auto& i:fus)
    {
        i.wait();
        cout<<i.get()<<endl;
    }

    return 0;
}