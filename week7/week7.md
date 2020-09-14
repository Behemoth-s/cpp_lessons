## 文件和流
标准库`ifstream` 读文件, `ofstream` 写文件, `fstream` 读写文件
创建文件流
```c++
#include <fstream>
ofstream outFile("clients.dat", ios::out|ios::binary);
```
使用`ofstream.open`
```c++
ofstream fout
fout.open("test.out", ios::out|ios::binary);
if(!fout) {cerr << "File open error!"<<endl;}
```

## 函数模板
函数模板就是C++里面的泛型
```c++
template <class T>
void Swap(T &x, T&y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <class T1, class T2>
void Print(T1 &x, T2 &y)
{

}
```
函数模板可以重载

编译器按如下顺序选择
1. 参数完全匹配的普通函数
2. 参数完全匹配的函数模板
3. 参数自动转换后匹配的普通函数
4. 报错

## 类模板

```c++
template <class T1,class T2, int sz>
class A
{
private:
    T1 t1[sz]
    T2 t2
public:
    A(T[] a):t1(a){}
    template <class T3>
    void func(T3){}

};
template <class int, class double, int sz>
class B:public A <int, double>
{
private:


};
```