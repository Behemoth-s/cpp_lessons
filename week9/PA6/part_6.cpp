/**
 * 描述
 * 我们定义一个正整数a比正整数b优先的含义是：
 *
 * *a的质因数数目（不包括自身）比b的质因数数目多；
 * *当两者质因数数目相等时，数值较大者优先级高。
 *
 * 现在给定一个容器，初始元素数目为0，之后每次往里面添加10个元素，每次添加之后，
 * 要求输出优先级最高与最低的元素，并把该两元素从容器中删除。
 *
 * 输入
 * 第一行: num (添加元素次数，num <= 30)
 *
 * 下面10*num行，每行一个正整数n（n < 10000000).
 *
 * 输出
 * 每次输入10个整数后，输出容器中优先级最高与最低的元素，两者用空格间隔。
 *
 * 样例输入
 *
 * 1
 * 10 7 66 4 5 30 91 100 8 9
 * 样例输出
 * 66 5
**/
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <set>
#include <math.h>
using namespace std;

int prime_number(int n)
{
    set<int> primes = set<int>();
    primes.insert(n);
    while (n % 2 == 0)
    {
        // cout << "2\t";
        n = n / 2;
        primes.insert(2);
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            // cout << i << "\t";
            n = n / i;
            primes.insert(i);
        }
    }
    if (n > 2)
        // cout << n << "\t";
        primes.insert(n);
    return primes.size();
}
bool compare(int a, int b)
{
    bool flag = a < b;
    a = prime_number(a);
    b = prime_number(b);
    if (a < b)
        return true;
    else if (a == b)
        return flag;
    else
        return false;
}

int main()
{
    freopen("week9/part6_example.txt", "r", stdin);
    int N;
    int num;
    priority_queue<int, vector<int>, decltype(&compare)> pq(compare);
    auto vec = vector<int>();
    string line;
    istringstream iss;
    getline(cin, line);
    iss = istringstream(line);
    iss >> N;
    int count = 10;

    while (N--)
    {
        while (count--)
        {
            getline(cin, line);
            iss = istringstream(line);
            iss >> num;
            pq.push(num);
        }
        cout << pq.top() << " ";
        while (!pq.empty())
        {
            pq.pop();
            vec.push_back(pq.top());
        }

        cout << vec.back() << endl;
        vec.pop_back();
        while (!vec.empty())
        {
            pq.push(vec.back());
            vec.pop_back();
        }
        count = 10;
    }
}