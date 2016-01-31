#include <iostream>

using namespace std;

void Read_Unknown_Number_of_Inputs()
{
	int sum = 0, value = 0;
	// 读取数据直到遇到文件尾（或无效输入，如这里读入的不是整数）
	// 文件结束符：windows下敲ctrl+z，然后按Enter
	// Unix下ctrl+D
	while (std::cin >> value)
		sum += value;
	std::cout << "Sum is: " << sum << std::endl;
}

int main()
{
	Read_Unknown_Number_of_Inputs();
	return 0;
}