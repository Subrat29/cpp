#include <bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    int age;
    int wt;

    void speak()
    {
        cout << "Speak bro" << endl;
    }

};

class Dog: public Animal 
{
    

};

int main()
{
    Dog d1;
    d1.speak();

    return 0;
}