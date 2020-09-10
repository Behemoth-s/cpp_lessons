#include <iostream>
using namespace std;

/**
 * 下面程序的输出结果是：
 * destructor B
 * destructor A
 **/

class A
{
public:
    virtual ~A() { cout << "destructor A" << endl; }
};
class B : public A
{
public:
    ~B() { cout << "destructor B" << endl; }
};
int main()
{
    A *pa;
    pa = new B;
    delete pa;
    return 0;
}