
#include <iostream>       // std::cerr
#include <stdexcept>      // std::out_of_range
#include <vector>         // std::vector

void out_of_range_example()
{
	std::vector<int> myvector(10);
	try {
		myvector.at(20)=100;      // vector::at throws an out-of-range
	}
	catch (const std::out_of_range& oor) {
		std::cerr << "Out of Range error: " << oor.what() << '\n'; 
	}

}

int main (void) 
{
  out_of_range_example(); // Out of Range error: vector::_M_range_check
  return 0;
}