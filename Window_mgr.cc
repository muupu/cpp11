#include <vector>
#include <Screen.h>

class Window_mgr {
public:
	// 窗口中每个屏幕的编号
	using ScreenIndex = std::vector<Screen>::size_type; 
	// 将指定的Screen重置为空白
	void clear(ScreenIndex);

	ScreenIndex addScreen(const Screen&); // 添加一个Screen，返回它的编号

private:
	std::vector<Screen> screens{Screen(24,80, ' ')}; // Window_mgr开始时总是拥有一个默认初始化的Screen
};

void Window_mgr::clear(ScreenIndex i)
{
	Screen &s = screens[i];  // s是一个引用
	// 这里s能够访问私有成员contents（因为Window_mgr是Screen的友元类）
	s.contents = string(s.height * s.width, ' ');  
}

// 返回类型出现在类名之前，属于Window_mgr类的作用域之外。必须明确指定哪个类定义了它。 
Window_mgr::ScreenIndex    
Window_mgr::addScreen(const Screen &s)
{
	screens.push_back(s);
	return screens.size() - 1;
}
