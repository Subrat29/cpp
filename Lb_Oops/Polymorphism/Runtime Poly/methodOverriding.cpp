#include <bits/stdc++.h>
using namespace std;

class Animal 
{
    public:
    void speak()
    {
        cout << "Speak" << endl;
    }
};

class Dog: public Animal
{
    public:
    void speak()
    {
        cout << "Bark" << endl;
    }
};

int main()
{
    Dog g;
    g.speak();
    return 0;
}