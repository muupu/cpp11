#include <string>

class Screen {
public:
	using pos = std::string::size_type;
	Screen() = default; // 因为Screen有另外一个构造函数，所以需要该构造函数
	Screen(pos ht, pos wd, char c): height(ht), width(wd),
	       contents(ht* wd, c) {}
	char get() const { return contents[cursor];} // 读取光标处的字符；隐式内联
	inline char get{pos ht, pos wd} const;       // 显示内联
	Screen &move(pos r, pos c);                  // 能在之后被设为内联

	void some_member() const; // 尽管是const成员函数，仍能够改变access_ctr的值

	Screen &set(char);
	Screen &set(pos, pos, char);

	Screen &display(std::ostream &os)
	{ do_display(os); return *this;}

	const Screen &display(std::ostream &os) const
	{ do_display(os); return *this;}

	// friend class Window_mgr; // Window_mgr的成员可以访问Screen类的私有部分
	friend void Window_mgr::clear(ScreenIndex); // Window_mgr::clear必须在Screen类之前被声明

private:
	void do_display(std::ostream &os) const {os << contents;}

	mutable size_t access_ctr; // 即使在一个const对象内也能被释放
	pos cursor = 0;
	pos height = 0, width = 0;
    std::string contents;
};

inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this;          // 以左值的形式返回对象
}

char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row + c];
}

void Screen::some_member() const
{
	++access_ctr;  // 保存一个计数值，用于记录成员函数被调用的次数。（这种需求有时候会有的！）
}

// 返回*this，返回的是对象本身
// 这样就能将一系列操作连接在一条表达式中！
// 例如：myScreen.move(4, 0).set('#') --- 将光标move到指定位置(4, 0)，然后设置该位置的字符值('#')
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;
	return *this;
}

