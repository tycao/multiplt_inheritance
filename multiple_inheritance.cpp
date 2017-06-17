#include <iostream>
#include <memory>
using namespace std;

struct Base1
{
public:
    Base1() = default;
    Base1(const std::string&);
    Base1(std::shared_ptr<int>);
};

struct Base2
{
    Base2() = default;
    Base2(const std::string&);
    Base2(std::shared_ptr<int>);
};

struct D1 : public Base1, public Base2
{
    using Base1::Base1;
    using Base2::Base2;

    //  如果一个类从它的多个基类中，继承了相同的构造函数...
    //  ....则这个类必须为该构造函数定义自己的版本
    D1() = default;
    D1(const string& s) : Base1(s), Base2(s) { }
    D1(std::shared_ptr<int>);
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
