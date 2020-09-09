
#include <iostream>
using namespace std;

class Class1
{
public:
    inline void func();
    void func2()
    {
        cout << "func2" << endl;
    };
};
void Class1::func()
{
    cout << "func1" << endl;
}
int main(int argc, char *argv[])
{
    Class1 c;
    c.func();
    c.func2();
}