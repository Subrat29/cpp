#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    void func()
    {
        cout << "FN 1" << endl;
    }
};

class B
{
public:
    void func()
    {
        cout << "FN 2" << endl;
    }
};

class C : public A, public B
{
public:
    void func3()
    {
        cout << "FN 3" << endl;
    }
};


int main()
{
    C obj;
    obj.A::func();
    obj.B ::func();
    obj.func3();

    return 0;
}