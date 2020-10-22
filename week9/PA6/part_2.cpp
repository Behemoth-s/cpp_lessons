#include <iostream>
#include <string>
using namespace std;
/**
 * 描述
写一个自己的 CMyistream_iterator 模板，
使之能和 istream_iterator 模板达到一样的效果，即：

输入：
79 90 20 hello me

输出：
79

79,90,20

hello,me
**/
// 在此处补充你的代码
template <class T>
class CMyistream_iterator
{
    istream &r;
    T v;

public:
    CMyistream_iterator(istream &rr) : r(rr)
    {
        r >> v;
    }
    CMyistream_iterator &operator++()
    {
        r >> v;
        return *this;
    }
    CMyistream_iterator &operator++(int)
    {
        r >> v;
        return *this;
    }
    const T &operator*()
    {
        return v;
    }
};

int main()
{
    CMyistream_iterator<int> inputInt(cin);
    int n1, n2, n3;
    n1 = *inputInt; //读入 n1
    int tmp = *inputInt;
    cout << tmp << endl;
    inputInt++;
    n2 = *inputInt; //读入 n2
    inputInt++;
    n3 = *inputInt; //读入 n3
    cout << n1 << "," << n2 << "," << n3 << endl;
    CMyistream_iterator<string> inputStr(cin);
    string s1, s2;
    s1 = *inputStr;
    inputStr++;
    s2 = *inputStr;
    cout << s1 << "," << s2 << endl;
    return 0;
}