## 运算符重载

运算符可以重载为成员函数或者普通函数，成员函数时当前对象为运算符函数的第一个参数

```c++
class Complex
{
public:
    int real;
    int imag;
    Complex(int a, iint b):real(a), imag(b){}
    
};
Complex Complex::operator+(const Complex &a)
    {
        return Complex(real+a.real, imag+b.imagimag+b.imag)；
    }

Complex operator+(const Complex &a, const Complex &b)
{
    return  Complex(a.real+b.real, a.imag+b.imag);
}

```

## 赋值运算符`=`重载

赋值运算符只能重载为成员函数。

```c++
class String
{
private:
    char* str;
public:
    String():str(NULL){}
    const char* c_str() {return str;}
    char * operator=(const char *s);
    ~String();
}
char* String::operator=(const char *s)
{
    if(str) delete []str;
    if(s)
    {
        str = new char[strlen(s)+1];
        strcpy(str, s);
    }else
    {
        str = NULL;
    }
    return str;
}
String::~String()
{
    if(str) delete []str;
}
```
**浅复制和深复制**

浅复制会导致两个类指向同意内存

```c++
String & String::operator=(const String &s)
{   
    if (str == s.str) return *this;
    if(str) delete []str;
    str = new char[strlen(s.str)+1];
    strcpy(str, s.str);
    return *this; 
}
String::String(String &s)
{
    if (s.str)
    {
        str = new char[strlen(s.str)+1];
        strcpy(str, s.str);
    }else
    {
        str=NULL;
    }
}
```
## 运算符重载为友元函数

`Complex::operator+`重载为成员函数后，其实质上为`Complex operator+(Complex, Complex)`,不能处理`operator+(Complex, int)`的情况，这种情况下可以定义友元函数`friend Complex operator+(double r, const Complex &c)`

```c++
friend Complex Complex::operator+(double r, const Complex &c)
{
    return Complex(c.real + r, c.imag);
}
```
##长度可变的整型数组
```c++
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
```

## 流插入运算符重载
`<<`左移运算符
`cout << 5 <<"this"`
```c++
ostream & ostream::operator<<(int n){}
ostream & ostream::operator<<(char * s){}
```
### example1
想要`cout.operator<<(CStudent &r)`输出age
```c++
class CStudent
{
public:
    int age;
}
ostream& operator(ostream &o, const CStudent &s)
{
    o<<s.age;
    return o;
}
int main()
{
    CStudent s(15);
    cout << s<<"age";
}
```
### example2
c为Complex对象，想要`cout<<c;`输出`a+bi`， `cin>>c`从键盘接收`"a+bi"`并赋值给c。
```c++
class Complex
{

    int real;
    int imag;
public:
    Complex(int a, int b):real(a), imag(b)
    {

    }
    friend ostream &operator<<(ostream &o, const Complex &c);
    friend istream &operator>>(istream &is, const Complex &c);

}
ostream &operator(ostream &o, const Complex &c)
{
    o<<c.real<<"+"<<c.imag<<"i";
    return o;
}
istream &operator>>(istream &is, const Complex &c)
{
    string s;
    is >> s;
    int pos = s.find("+",0)
    string stmp = s.substr(0, pos);
    c.real = stoi(stmp);
    stmp = s.substr(pos+1, s.length()-pos-2);
    c.imag = stoi(stmp);
    return is;
}
``

## 自加自减运算符重载

`++/--`运算符有前置和后置的区别
前置运算符为一元运算符，可以重载为成员函数或全局函数
```c++
T T::operator++();
T operator++(T);
```
后置运算符作为二元运算符重载，但第二个参数并无意义
```c++
T T::operator++(int);
T operator++(T, int);
```

example 
```c++
class CDemo
{
private:
    ind n;
public:
    CDemo(int i):n(i){}
    CDemo operator++();
    CDemo operator++(int);
    CDemo operator--();
    CDemo operator--(int);
    operator int(){return n}; //前置类型转换运算符
}
CDemo CDemo::operator++()
{
    n++;
    return *this;
}
CDemo CDemo::operator++(int)
{
    CDemo tmp(*this)
    n++;
    return tmp;
}
CDemo CDemo::operator--()
{
    n--;
    return *this;
}
CDemo CDemo::operator--(int)
{
    CDemo tmp(*this)
    n--;
    return tmp;
}
```

## 类型转换运算符

`operator int(){}`

## 运算符重载要点

1. 不能定义新的运算符
2. 重载不改变运算符的优先级
3. 部分运算符不能重载，如`.` `::` `?:` 