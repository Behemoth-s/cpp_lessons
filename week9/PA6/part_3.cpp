/**
 * 注意： 总时间限制: 5000ms 内存限制: 100000kB

描述
现有一整数集（允许有重复元素），初始为空。我们定义如下操作：

add x 把x加入集合

del x 把集合中所有与x相等的元素删除

ask x 对集合中元素x的情况询问

对每种操作，我们要求进行如下输出。

add 输出操作后集合中x的个数

del 输出操作前集合中x的个数

ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），再输出当前集合中x的个数，中间用空格格开。

输入
7
add 1
add 1
ask 1
ask 2
del 2
del 1
ask 1
第一行是一个整数n，表示命令数。0<=n<=100000。

后面n行命令，如Description中所述。

输出
共n行，每行按要求输出。
1
2
1 2
0 0
0
2
1 0
样例输入
**/
#include <iostream>
#include <set>
#include <string>
#include <sstream>
using namespace std;
void add(int val, multiset<int> &msets, set<int> &keys)
{
    // add x 把x加入集合
    // add 输出操作后集合中x的个数
    msets.insert(val);
    keys.insert(val);
    cout << msets.count(val) << endl;
}
void ask(int val, multiset<int> &msets, set<int> &keys)
{
    // ask x 对集合中元素x的情况询问
    // ask 先输出0或1表示x是否曾被加入集合（0表示不曾加入），
    // 再输出当前集合中x的个数，中间用空格格开。

    cout << keys.count(val) << " " << msets.count(val) << endl;
}
void del(int val, multiset<int> &msets, set<int> &keys)
{
    cout << msets.count(val) << endl;

    // del x 把集合中所有与x相等的元素删除
    // del 输出操作前集合中x的个数
    msets.erase(val);
    // for (auto i = msets.begin(); i != msets.end(); i++)
    // {
    //     if (*i == val)
    //     {
    //         msets.erase(i);
    //     }
    // }
}
int main()
{
    freopen("week9/part3_example.txt", "r", stdin);
    auto msets = multiset<int>();
    auto keys = set<int>();
    string line;
    string op;
    int val;
    int n;
    istringstream iss;
    getline(cin, line);
    iss = istringstream(line);
    iss >> n;

    while (n--)
    {
        getline(cin, line);
        iss = istringstream(line);
        iss >> op >> val;
        if (op.compare("add") == 0)
            add(val, msets, keys);
        else if (op.compare("del") == 0)
            del(val, msets, keys);
        else if (op.compare("ask") == 0)
            ask(val, msets, keys);
    }
}