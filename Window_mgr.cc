#include <vector>
#include <Screen.h>

class Window_mgr {
public:
	// 窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type; 
	// 将指定的Screen重置为空白
	void clear(ScreenIndex);

private:
	std::vector<Screen> screens{Screen(24,80, ' ')}; // Window_mgr开始时总是拥有一个默认初始化的Screen
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];  // s是一个引用
	// 这里s能够访问私有成员contents（因为Window_mgr是Screen的友元类）
	s.contents = string(s.height * s.width, ' ');  
}

