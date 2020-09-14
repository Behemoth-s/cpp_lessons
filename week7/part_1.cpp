#include <iostream>
using namespace std;
/**
 * 下面程序输出结果是：
 * 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,
 * 29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,
 * 54,55,56,57,58,59,
 *
 **/
// 在此处补充你的代码
template <class T>
class CArray3D
{
private:
    T ***ptr3D = NULL;

public:
    CArray3D(int a, int b, int c)
    {
        ptr3D = new T **[a];
        for (int i = 0; i < a; i++)
        {
            ptr3D[i] = new T *[b];
            for (int j = 0; j < b; j++)
                ptr3D[i][j] = new T[c];
        }
    }
    T **operator[](int i)
    {
        return ptr3D[i];
    }
};
int main()
{
    CArray3D<int> a(3, 4, 5);
    int No = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 5; ++k)
                a[i][j][k] = No++;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 4; ++j)
            for (int k = 0; k < 5; ++k)
                cout << a[i][j][k] << ",";
    return 0;
}