## 继承和派生

派生类拥有基类的全部成员对象和函数，且基类成员位于派生类的声明之前

但是派生类不能直接访问基类的private成员

protected 限定子类的成员函数访问

声明方式如下：
`class Children:public Parent`

派生类声明的同名的成员会覆盖基类的成员，可以通过`base::var`来访问基类成员

### 派生类的构造函数
派生类的对象同时也包含基类对象
在执行派生类的构造函数之前，先执行基类的构造函数
构造函数声明如下：
```c++
Children::Children(int a, int b):Parent(int a),b(b){}
```

### public 继承的赋值兼容规则
```c++
class base {};
class derived: public base {};
base b;
dervied d;
```
1. 派生类对象可以赋值给基类对象
```cpp
b = d;
```
2. 派生类对象可以初始化基类引用
```cpp
base &br = d;
```
3. 派生类对象的地址可以赋值给基类指针
```cpp
base *pb = & d;
```