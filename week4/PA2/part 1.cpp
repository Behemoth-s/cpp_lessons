#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
/*
输入
无

输出
3+4i

5+6i
*/
class Complex
{
private:
    double r, i;

public:
    void Print()
    {
        cout << r << "+" << i << "i" << endl;
    }
    Complex &operator=(const string &a)
    {
        // string a(s);
        int pos = a.find("+");
        r = stod(a.substr(0, pos));
        i = stod(a.substr(pos + 1, a.length() - pos - 2));
        return *this;
    }
    // 在此处补充你的代码
};
int main()
{
    Complex a;
    a = "3+4i";
    a.Print();
    a = "5+6i";
    a.Print();
    return 0;
}