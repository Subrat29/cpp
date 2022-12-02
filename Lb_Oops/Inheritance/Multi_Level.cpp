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

class Desikutta: public Dog
{
    
};

int main()
{
    Desikutta dk;
    dk.speak();

    return 0;
}