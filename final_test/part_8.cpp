/**
 * 描述
输入整数 n ( 0 <=n<= 2^30) , 以及整数i,j(0 <= i,j <31,i < j-1),
输出整数k(按十六进制输出结果 )，k的第i位和n相同，第j位和n不同，
i,j之间的位是1, 其他位都是0。
这里提到的所有的位，指的都是二进制位，最右边算第0位。

输入
第一行是整数 t，表示数据组数。

每组输入数据是一行，三个整数 n,i和j。

输出
对每组输入数据，按十六进制输出结果。

样例输入
2
23 3 5
7 0 2
样例输出
30
3
**/
#include <iostream>
#include <bitset>

using namespace std;
int main()
{
    int t;
    cin >> t;
    int n, i, j;
    while (t--)
    {
        cin >> n >> i >> j;
        int k;
        k = (n & (1 << j) ^ (1 << j)) | (n & (1 << i)) | ((1 << j) - (1 << (i + 1)));
        cout << k << "\n";
        cout << std::bitset<32>(n) << "\n"
             //  << bitset<32>(n & (1 << j) ^ (1 << j)) << "\n"
             //  << bitset<32>((n & (1 << i))) << "\n"

             //  << std::bitset<32>((1 << j) - (1 << (i + 1))) << "\n"
             << std::bitset<32>(k) << "\n";
    }
}