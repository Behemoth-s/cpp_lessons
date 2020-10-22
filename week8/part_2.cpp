/**
 * 描述
 * 写一个程序完成以下命令：
 * new id ——新建一个指定编号为id的序列(id<10000)
 * add id num——向编号为id的序列加入整数num
 * merge id1 id2——合并序列id1和id2中的数，并将id2清空
 * unique id——去掉序列id中重复的元素
 * out id ——从小到大输出编号为id的序列中的元素，以空格隔开
 *
 * 输入
 * 第一行一个数n，表示有多少个命令( n＜＝２０００００)。以后n行每行一个命令。
 * 16
 * new 1
 * new 2
 * add 1 1
 * add 1 2
 * add 1 3
 * add 2 1
 * add 2 2
 * add 2 3
 * add 2 4
 * out 1
 * out 2
 * merge 1 2
 * out 1
 * out 2
 * unique 1
 * out 1
 * 输出
 * 按题目要求输出。
 * 1 2 3
 * 1 2 3 4
 * 1 1 2 2 3 3 4
 *
 * 1 2 3 4
 **/
#include <iostream>
#include <vector>
#include <sstream>
#include <list>
#include <map>
using namespace std;
int main()
{
    freopen("week8/part2_example.txt", "r", stdin);

    map<int, list<int>> sets_;
    string line;
    string op;
    istringstream iss;

    getline(cin, line);
    iss = istringstream(line);
    int p1, p2;
    int n;
    iss >> n;
    while (n-- > 0)
    {
        getline(cin, line);
        iss = istringstream(line);
        iss >> op;
        if (op.compare("new") == 0)
        {
            // new id ——新建一个指定编号为id的序列(id<10000)
            iss >> p1;
            list<int> new_list;
            sets_[p1] = new_list;
        }
        else if (op.compare("add") == 0)
        {
            // add id num——向编号为id的序列加入整数num
            iss >> p1;
            iss >> p2;
            sets_[p1].push_back(p2);
        }
        else if (op.compare("merge") == 0)
        {
            //merge id1 id2——合并序列id1和id2中的数，并将id2清空
            iss >> p1;
            iss >> p2;
            sets_[p1].merge(sets_[p2]);
        }
        else if (op.compare("unique") == 0)
        {
            // unique id——去掉序列id中重复的元素
            iss >> p1;
            sets_[p1].unique();
        }
        else if ("out")
        {
            //out id ——从小到大输出编号为id的序列中的元素，以空格隔开
            iss >> p1;
            sets_[p1].sort();
            for (auto it = sets_[p1].begin(); it != sets_[p1].end(); it++)
            {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
    return 0;
}