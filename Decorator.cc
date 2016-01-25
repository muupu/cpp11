
class IHello
{
public:
    virtual ~IHello() {}       // 将多态基类的析构函数声明为virtual
    virtual void show() = 0;
                    // 子类只有实现该接口才可进行对象的实例化工作
};

class Hello :public IHello
{
private:
    std::string _name;
public:
    Hello(const std::string& name):_name(name){}
    void show() { std::cout << "hello " + _name << std::endl;}
};

