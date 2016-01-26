#include <iostream.h>
class Base
{
private:
        int b_number;
public:
        Base( ){}
        Base(int i) : b_number (i) { }
        int get_number( ) {return b_number;}
        void print( ) {cout << b_number << endl;}        
};

