#include <iostream>
using namespace std;
/*
输入
无

输出
4,1
*/
class MyInt
{
    int nVal;

public:
    MyInt(int n) { nVal = n; }
    int ReturnVal() { return nVal; }
    MyInt &operator-(int a)
    {
        nVal -= a;
        return *this;
    }
    // 在此处补充你的代码
};
int main()
{
    MyInt objInt(10);
    objInt - 2 - 1 - 3;
    cout << objInt.ReturnVal();
    cout << ",";
    objInt - 2 - 1;
    cout << objInt.ReturnVal();
    return 0;
}