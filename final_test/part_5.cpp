/**
 * 输入一个正整数构成的数组a[0], a[1], a[2], ... , a[n-1], 计算它们的二进制低3位之和。
输入
数组a,以0表示输入结束。
1 3 9 7 3 6 20 15 18 17 4 8 18 0
输出
一个整数 , 所输入数组各元素的二进制低3位之和。
41
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CMy_add
{

public:
    int &my_sum;
    CMy_add(int &my_s) : my_sum(my_s)
    {
    }
    void operator()(int v)
    {
        my_sum += v & 7;
    }
};
int main(int argc, char *argv[])
{
    int v, my_sum = 0;
    vector<int> vec;
    cin >> v;
    while (v)
    {
        vec.push_back(v);
        cin >> v;
    }
    for_each(vec.begin(), vec.end(), CMy_add(my_sum));
    cout << my_sum << endl;
    return 0;
}