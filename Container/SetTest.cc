// unordered_set/set
#include <iostream>
#include <string>
#include <array>
#include <unordered_set>

void print_unordered_set(std::unordered_set<std::string>& myset)
{
  std::cout << "myset contains:";
  for (const std::string& x: myset) std::cout << " " << x;
  std::cout <<  std::endl;
}

void test_unordered_set_insert()
{
  std::unordered_set<std::string> myset = {"yellow","green","blue"};
  std::array<std::string,2> myarray = {"black","white"};
  std::string mystring = "red";
  print_unordered_set(myset);

  myset.insert (mystring);                        // copy insertion
  print_unordered_set(myset);

  myset.insert (mystring+"dish");                 // move insertion
  print_unordered_set(myset);

  myset.insert (myarray.begin(), myarray.end());  // range insertion
  print_unordered_set(myset);

  myset.insert ( {"purple","orange"} );           // initializer list insertion
  print_unordered_set(myset);

}

int main ()
{
  test_unordered_set_insert;
  return 0;
}