#include <vector>
#include <Screen.h>

class Window_mgr {
private:
	std::vector<Screen> screens{Screen(24,80, ' ')}; // Window_mgr开始时总是拥有一个默认初始化的Screen
}