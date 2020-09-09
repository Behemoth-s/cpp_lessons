#include "monster_war.hpp"
#include <iostream>
// #include <cstdint>
#include <cstring>
// #include <iomanip>
using namespace std;
class CArray
{
private:
    int size;
    int *ptr;

public:
    void push_back(int val);
    int length()
    {
        return size;
    }
    int &operator[](int i)
    {
        return ptr[i];
    }
    CArray &operator=(const CArray &r);
    CArray(int s = 0);
    CArray(CArray &r);
    ~CArray();
};
CArray::CArray(int s) : size(s)
{
    if (s == 0)
        ptr = NULL;
    else
    {
        ptr = new int[s];
    }
}
CArray::CArray(CArray &r)
{
    if (!r.ptr)
    {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[r.size];
    memcpy(ptr, r.ptr, sizeof(int) * r.size);
    size = r.size;
}
CArray::~CArray()
{
    if (ptr)
        delete[] ptr;
}
CArray &CArray::operator=(const CArray &r)
{
    if (ptr == r.ptr)
        return *this;
    if (r.ptr == NULL)
    {
        if (ptr)
            delete[] ptr;
        ptr = NULL;
        size = 0;
        return *this;
    }
    else
    {
        if (size < r.size)
        {
            delete[] ptr;
            ptr = new int[r.size];
        }
        memcpy(ptr, r.ptr, sizeof(int) * r.size);
        size = r.size;
        return *this;
    }
}
void CArray::push_back(int v)
{
    // to do implement efficient push_back
    if (ptr)
    {
        int *newPtr = new int[size + 1];
        memcpy(newPtr, ptr, sizeof(int) * size);
        delete[] ptr;
        ptr = newPtr;
    }
    else
    {
        ptr = new int[1];
    }
    ptr[size++] = v;
}
int main()
{
    CArray a; //
    for (int i = 0; i < 5; i++)
    {
        a.push_back(i);
    }
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i < a.length(); i++)
    {
        cout << a2[i] << " ";
    }
    a2 = a3;
    for (int i = 0; i < a2.length(); ++i)
    {
        cout << a2[i] << " ";
    }
    cout << endl;
    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i < a4.length(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}