## 虚函数
`virtual`关键字，定义虚函数
当基类指针指向派生类对象时，同名虚函数将调用派生类的实现
```c++
class Base
{
public:
    virtual void func(){}
};
```
通过基类指针和基类引用调用虚函数，则可以实现多态
**example**
```c++
class A
{
    public:
    virtual void print(){cout << "class A";}
};
class B
{
public:
    void print(){cout << "class B";}
};
class C
{
public:
    void print(){cout << "class C";}
};
class D
{
public:
    void print(){cout << "class D";}
};
int main()
{
    A* pa = new A();
    B b();
    C c();
    D d();
    (*pa)->print();
    pa = &b;
    (*pa)->print();
    pa = &c;
    (*pa)->print();
    pa = &d;
    (*pa).print();
}
```
example2
```c++

class CShape
{
public:
    virtual void double() Area()=0;
    virtual void PrintInfo()=0;
};

class CRectangle: public CShape
{
public:
    int w, h;
    virtual double Area()
    {
        return w*h;
    }
    virtual void PrintInfo()
    {
        cout << "Rectangle:"<< Area()<<endl;
    }
};

class CCircle: public CShape
{
public:
    int r;
    virtual double Area()
    {
        return 3.14 * r * r;
    }
    virtual void PrintInfo()
    {
        cout << "Circle:"<< Area()<<endl;

    }
};

class CTriangle: public CShape
{
public:
    int a, b, c
    virtual double Area()
    {
        double p = (a + b +c);
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    virtual void PrintInfo()
    {
        cout << "Triangle:"<< Area()<<endl;
    }
};
```
## 构造函数不能是虚函数

## 虚函数多态的实现
简单来说，有虚函数的类会在对象内有一个地址指向类的所有虚函数地址的虚函数表

执行过程中，会首先查询函数是否是虚函数，然后再判断执行基类或者派生类的实现

## 虚析构函数
为了解决基类指针指向派生类对象在析构时的问题，含有虚函数的基类需要将基类的函数定义为`virtual`

## 纯虚函数
```c++
virtual void func()=0;
```
## 抽象类
包含纯虚函数的类
不能被实例化
可以声明指针和引用
抽象类的成员函数可以调用纯虚函数，构造和析构函数不能调用纯虚函数（因为不能被实例化）
