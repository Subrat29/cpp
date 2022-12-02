#include <bits/stdc++.h>
using namespace std;
    
class A
{
    public: 
    void say()
    {
        cout << "Hello janu" << endl;
    }

    void say(string name)
    {
        cout << "Hello baby" << endl;
    }
};

int main()
{
    A obj;
    obj.say();
    obj.say("gf");
    return 0;
}