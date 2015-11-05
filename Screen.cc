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

private:
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