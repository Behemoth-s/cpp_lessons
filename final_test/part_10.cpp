/**
 * 输入
不需要输入。

输出
使得程序的输出结果是：

2

3

B::destructor

A::destructor

3

4

B::destructor

A::destructor

3

B::destructor

A::destructor

A::destructor

A::destructor

样例输入
**/
#include <iostream>
#include <map>
using namespace std;
// 在此处补充你的代码
class A
{
public:
    static int count;
    A(int val)
    {
        count++;
    }
    A()
    {
        count++;
    }
    A(A &a)
    {
        count++;
    }
    virtual ~A()
    {
        cout << "A::destructor" << endl;
        count--;
    }
};
class B : public A
{
public:
    B(int val) : A() {}
    virtual ~B()
    {
        cout << "B::destructor" << endl;
    }
};
ostream &operator<<(ostream &os, A obj)
{
    os << obj.count;
    return os;
}
int A::count = 0;
void func(B b) {}
int main()
{
    A a1(5), a2;
    cout << A::count << endl;
    B b1(4);
    cout << A::count << endl;
    func(b1);
    cout << A::count << endl;
    A *pa = new B(4);
    cout << A::count << endl;
    delete pa;
    cout << A::count << endl;
    return 0;
}