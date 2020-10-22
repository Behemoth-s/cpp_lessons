/**
 * 请写出 MyString类，使得下面程序的输出结果符合下面的要求。
输入
无

输出
1. abcd-efgh-abcd-

2. abcd-

3.

4. abcd-efgh-

5. efgh-

6. c

7. abcd-

8. ijAl-

9. ijAl-mnop

10. qrst-abcd-

11. abcd-qrst-abcd- uvw xyz

about

big

me

take

abcd

qrst-abcd-
**/
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
// 在此处补充你的代码
class MyString
{
public:
    char *s;
    int size;
    MyString() {}
    // MyString(const string &s) : s(s) {}
    MyString(const char *r)
    {
        size = strlen(r);
        char ptr[100];
        memcpy(ptr, r, size + 1);
        s = ptr;
    }
    MyString(const MyString &obj)
    {
        size = obj.size;
        char ptr[100];
        memcpy(ptr, obj.s, size + 1);
        s = ptr;
    }
    friend ostream &operator<<(ostream &os, MyString &ms);
    friend MyString &operator+(string s_, MyString &ms);
    MyString operator+(MyString &obj)
    {
        int nsize = size + obj.size;
        char ptr[nsize];
        strcat(ptr, s);
        strcat(ptr, obj.s);
        return MyString(ptr);
    }
    MyString operator+(const char *s2)
    {
        int nsize = size + strlen(s2);
        char ptr[nsize];
        strcpy(ptr, s);
        strcpy(ptr + size, s2);
        MyString newobj = MyString(ptr);
        return newobj;
    }
    void operator+=(const char *s2)
    {
        char *ptr;
        strcpy(ptr, s);
        strcat(ptr, s2);
        s = ptr;
    }
    char &operator[](int n)
    {
        return s[n];
    }
    char *operator()(int a, int b)
    {
        char *ptr;
        strncpy(ptr, s + a, b);
        return ptr;
    }

    void operator=(const char *s2)
    {
        // s = ptr;
        char *ptr;
        strcpy(ptr, s2);
        s = ptr;
    }
    bool operator==(MyString &obj)
    {
        return strcmp(s, obj.s) == 0;
    }
    bool operator<(MyString &obj)
    {
        return strcmp(s, obj.s) < 0;
    }
    bool operator>(MyString &obj)
    {
        return strcmp(s, obj.s) > 0;
    }
};
ostream &operator<<(ostream &os, MyString &obj)
{
    cout << obj.s;
    return os;
}
// MyString operator+(string &s_, MyString &obj)
// {
//     MyString newobj = MyString(s_ + obj.s);
//     return newobj;
// }
MyString operator+(const char *s_, MyString &obj)
{
    char *ptr;
    strcpy(ptr, s_);
    strcpy(ptr, obj.s);
    return MyString(ptr);
}
int CompareString(const void *e1, const void *e2)
{
    MyString *s1 = (MyString *)e1;
    MyString *s2 = (MyString *)e2;
    if (*s1 < *s2)
        return -1;
    else if (*s1 == *s2)
        return 0;
    else if (*s1 > *s2)
        return 1;
    return 1;
}
int main()
{
    MyString s1("abcd-");
    MyString s2;
    MyString s3("efgh-");
    MyString s4(s1);
    MyString SArray[4] = {"big", "me", "about", "take"};
    cout << "1. " << s1 << s2 << s3 << s4 << endl;
    s4 = s3;
    s3 = s1 + s3;
    cout << "2. " << s1 << endl;
    cout << "3. " << s2 << endl;
    cout << "4. " << s3 << endl;
    cout << "5. " << s4 << endl;
    cout << "6. " << s1[2] << endl;
    s2 = s1;
    s1 = "ijkl-";
    s1[2] = 'A';
    cout << "7. " << s2 << endl;
    cout << "8. " << s1 << endl;
    s1 += "mnop";
    cout << "9. " << s1 << endl;
    s4 = "qrst-" + s2;
    cout << "10. " << s4 << endl;
    s1 = s2 + s4 + " uvw " + "xyz";
    cout << "11. " << s1 << endl;
    qsort(SArray, 4, sizeof(MyString), CompareString);
    for (int i = 0; i < 4; i++)
        cout << SArray[i] << endl;
    //s1的从下标0开始长度为4的子串
    cout << s1(0, 4) << endl;
    //s1的从下标5开始长度为10的子串
    cout << s1(5, 10) << endl;
    return 0;
}