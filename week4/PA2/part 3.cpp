#include <iostream>
#include <cstring>
using namespace std;

/*
输入
无

输出
0,1,2,3,

4,5,6,7,

8,9,10,11,

next

0,1,2,3,

4,5,6,7,

8,9,10,11,
*/

class Array2
{
private:
    int nrow, ncol;
    int **p;

public:
    Array2(){};
    Array2(int a, int b) : nrow(a), ncol(b)
    {
        p = new int *[nrow];
        for (int i = 0; i < nrow; i++)
        {
            p[i] = new int[ncol];
        }
    }
    Array2(Array2 &r)
    {
        if (p == r.p)
            return;
        if (p)
        {
            if ((nrow == r.nrow) && (ncol == r.ncol))
            {
            }
            else if (nrow == r.nrow)
            {
                for (int i = 0; i++; i < nrow)
                {
                    delete[] p[i];
                    p[i] = new int[r.ncol];
                }
            }
            else
            {
                for (int i = 0; i++; i < nrow)
                    delete[] p[i];
                delete[] p;
                p = new int *[r.nrow];
                for (int i = 0; i++; i < r.nrow)
                    p[i] = new int[r.ncol];
            }
        }
        nrow = r.nrow;
        ncol = r.ncol;
        for (int i = 0; i < nrow; i++)
            for (int j = 0; j < ncol; j++)
                p[i][j] = r.p[i][j];
    }
    int *operator[](int i)
    {
        return p[i];
    }
    int operator()(int i, int j)
    {
        return p[i][j];
    }
    ~Array2()
    {
        for (int i = 0; i++; i < nrow)
            delete[] p[i];
        delete[] p;
    }
};
int main()
{
    Array2 a(3, 4);
    int i, j;
    for (i = 0; i < 3; ++i)
        for (j = 0; j < 4; j++)
            a[i][j] = i * 4 + j;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << a(i, j) << ",";
        }
        cout << endl;
    }
    cout << "next" << endl;
    Array2 b;

    b = a;
    for (i = 0; i < 3; ++i)
    {
        for (j = 0; j < 4; j++)
        {
            cout << b[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}