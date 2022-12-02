#include <bits/stdc++.h>
using namespace std;

class B
{
    public:
    int a;
    int b;

    int add()
    {
        return a+b;
    }

    void operator + (B &obj)
    {
        int value1 = this->a;
        int value2 = obj.a;
        cout << "Output: " << value2-value1 << endl;
    }

    void operator () ()
    {
        cout << "I am Bracket " << endl;
    }
};

int main()
{
    B obj3;
    obj3.a=1;
    obj3.b=2;
    cout << obj3.add() << endl;

    B obj1, obj2;
    obj1.a = 67;
    obj2.a = 9;
    obj1 + obj2;

    obj1();


    return 0;
}