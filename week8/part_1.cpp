
#include <iostream>
#include <iterator>
#include <set>
using namespace std;
/**
 * 下面的程序输出结果是:
 * 1 2 6 7 8 9
 **/
int main()
{
    int a[] = {8, 7, 8, 9, 6, 2, 1};
    set<int> v(a, a + 7);
    ostream_iterator<int> o(cout, " ");
    copy(v.begin(), v.end(), o);
    return 0;
}