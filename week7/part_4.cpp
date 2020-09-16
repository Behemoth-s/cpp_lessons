/**
 * 描述
 * 给定n个字符串（从1开始编号），每个字符串中的字符位置从0开始编号，长度为1-500，
 * 现有如下若干操作：
 *
 * copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
 *
 * add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，
 * 若不是，则作字符串加法，返回的值为一字符串。
 *
 * find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，
 * 若没有找到，返回字符串的长度。
 *
 * rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，
 * 若没有找到，返回字符串的长度。
 *
 * insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
 *
 * reset S N：将第N个字符串变为S。
 *
 * print N：打印输出第N个字符串。
 *
 * printall：打印输出所有字符串。
 *
 * over：结束操作。
 *
 * 其中N，X，L可由find与rfind操作表达式构成，S，S1，S2可由copy与add操作表达式构成。
 *
 * 输入
 * 第一行为一个整数n（n在1-20之间）
 * 接下来n行为n个字符串，字符串不包含空格及操作命令等。
 * 接下来若干行为一系列操作，直到over结束。
 *
 * 输出
 * 根据操作提示输出对应字符串。
 *
 * 输入
 * 3
 * 329strjvc
 * Opadfk48
 * Ifjoqwoqejr
 * insert copy 1 find 2 1 2 2 2
 * print 2
 * reset add copy 1 find 3 1 3 copy 2 find 2 2 2 3
 * print 3
 * insert a 3 2
 * printall
 * over
 *
 * 输出
 * Op29adfk48
 * 358
 * 329strjvc
 * Op29adfk48
 * 35a8
 **/
#include <iostream>
#include <stack>
#include <algorithm>
#include <sstream>

using namespace std;
const string OP[] = {"copy", "add", "find", "rfind", "insert", "reset", "print", "printall", "over"};

bool is_op(const string &s)
{
    return find(begin(OP), end(OP), s) != end(OP);
}
bool is_integer(const std::string &s)
{
    if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+')))
        return false;
    char *p;
    strtol(s.c_str(), &p, 10);
    return (*p == 0);
}
void copy(string s[], int sz, stack<string> &st)
{
    // copy N X L：取出第N个字符串第X个字符开始的长度为L的字符串。
    int N = stoi(st.top()) - 1;
    st.pop();
    int X = stoi(st.top()) - 1;
    st.pop();
    int L = stoi(st.top());
    st.pop();
    st.push(s[N].substr(X, L));
}
void add(string s[], int sz, stack<string> &st)
{
    // add S1 S2：判断S1，S2是否为0-99999之间的整数，若是则将其转化为整数做加法，
    // 若不是，则作字符串加法，返回的值为一字符串。

    string s1 = st.top();
    st.pop();
    string s2 = st.top();
    st.pop();
    if (is_integer(s1) && is_integer(s2))
    {
        int n1, n2;
        n1 = stoi(s1);
        n2 = stoi(s2);
        if (n1 > 0 && n1 < 99999 && n2 > 0 && n2 < 99999)
        {
            st.push(to_string(n1 + n2));
            return;
        }
        st.push(s1 + s2);
        return;
    }
}
void find(string s[], int sz, stack<string> &st)
{
    // find S N：在第N个字符串中从左开始找寻S字符串，返回其第一次出现的位置，
    // 若没有找到，返回字符串的长度。

    string s1 = st.top();
    st.pop();
    int n = stoi(st.top()) - 1;
    st.pop();
    size_t found = s[n].find(s1);
    if (found != std::string::npos)
    {
        st.push(to_string(found + 1));
    }
    else
    {
        st.push(to_string(s1.length()));
    }
    return;
}
void rfind(string s[], int sz, stack<string> &st)
{
    //  * rfind S N：在第N个字符串中从右开始找寻S字符串，返回其第一次出现的位置，
    //  * 若没有找到，返回字符串的长度。
    string s1 = st.top();
    st.pop();
    int n = stoi(st.top()) - 1;
    st.pop();

    size_t found = s[n].rfind(s1);
    if (found != std::string::npos)
    {
        st.push(to_string(found + 1));
    }
    else
    {
        st.push(to_string(s1.length()));
    }
    return;
}
void insert(string s[], int sz, stack<string> &st)
{
    //  * insert S N X：在第N个字符串的第X个字符位置中插入S字符串。
    string s1 = st.top();
    st.pop();
    int n = stoi(st.top()) - 1;
    st.pop();
    int x = stoi(st.top()) - 1;
    st.pop();

    s[n].insert(x, s1);
}
void reset(string s[], int sz, stack<string> &st)
{
    //  * reset S N：将第N个字符串变为S。
    string s1 = st.top();
    st.pop();
    int n = stoi(st.top()) - 1;
    st.pop();
    s[n] = s1;
}
void print(string s[], int sz, stack<string> &st)
{
    //  * print N：打印输出第N个字符串。
    int n = stoi(st.top()) - 1;
    st.pop();
    cout << s[n] << endl;
}
void printall(string s[], int sz, stack<string> &st)
{
    //  * printall：打印输出所有字符串。
    for (int i = 0; i < sz; i++)
    {
        cout << s[i] << endl;
    }
}
void handle(string s[], int sz, stack<string> &st, void (*f)(string[], int, stack<string> &))
{
    (*f)(s, sz, st);
}

int main()
{
    freopen("week7/example4.txt", "r", stdin);
    int N;

    string line;
    istringstream iss;
    getline(cin, line);
    iss = istringstream(line);

    iss >> N;
    string s[N];

    for (int i = 0; i < N; i++)
    {
        getline(cin, line);
        iss = istringstream(line);
        iss >> s[i];
    }

    string x;
    stack<string> st1;
    stack<string> st2;

Loop:
    getline(cin, line);
    iss = istringstream(line);
    iss >> x;
    if (x.compare("over") != 0)
    {
        st1.push(x);
        while (iss >> x)
        {
            st1.push(x);
        }
        while (!st1.empty())
        {
            // "copy", "add", "find", "rfind", "insert", "reset", "print", "printall"
            x = st1.top();
            st1.pop();
            if (x.compare("copy") == 0)
                handle(s, N, st2, copy);
            else if (x.compare("add") == 0)
                handle(s, N, st2, add);
            else if (x.compare("find") == 0)
                handle(s, N, st2, find);
            else if (x.compare("rfind") == 0)
                handle(s, N, st2, rfind);
            else if (x.compare("insert") == 0)
                handle(s, N, st2, insert);
            else if (x.compare("reset") == 0)
                handle(s, N, st2, reset);
            else if (x.compare("print") == 0)
                handle(s, N, st2, print);
            else if (x.compare("printall") == 0)
                handle(s, N, st2, printall);
            else
            {
                st2.push(x);
            }
        }
        goto Loop;
    }
}