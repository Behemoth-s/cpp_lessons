/**
 *
 * 输入
K个整数。除最后一个数据外，其他数据均不为0。
1 5 8 9 0
输出
K-1行。第I行输出第I个输入数和它的平方。
1 1
5 25
8 64
9 81
**/

#include <iostream>
using namespace std;
// 在此处补充你的代码
class CType
{
private:
    int n;

public:
    void setvalue(int a)
    {
        n = a;
    }
    int operator++(int)
    {
        return n;
    }
    friend ostream &operator<<(ostream &os, CType obj);
};
ostream &operator<<(ostream &os, CType obj)
{
    os << (obj.n * obj.n);
    return os;
}
int main(int argc, char *argv[])
{
    CType obj;
    int n;
    cin >> n;
    while (n)
    {
        obj.setvalue(n);
        cout << obj++ << " " << obj << endl;
        cin >> n;
    }
    return 0;
}