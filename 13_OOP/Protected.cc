#include <iostream>

// 派生类的成员或友元只能通过派生类对象来访问基类的受保护成员
// 
class Base {
protected:
	int prot_mem;
};

class Sneaky : public Base {
	friend void clobber(Sneaky&); // 能访问Sneaky::prot_mem
	friend void clobber(Base&);   // 不能访问Base::prot_mem
	int j;                        // j默认是private
};

// 正确：clobber能访问Sneaky对象的private和protected成员
void clobber(Sneaky &s) { 
	s.j = s.prot_mem = 0;	
}

// 错误：clobber不能访问Base的protected成员
void clobber(Base &b) {
	b.prot_mem = 0;
}