#include <bits/stdc++.h>
using namespace std;

class Animal
{
    public:
    int age;
    int wt;

    void sound()
    {
        cout << "Sound" << endl;
    }

};

class Human
{
    public:
    string color;

    void speak()
    {
        cout << "hii" << endl;
    }

};

class Hybrid: public Animal, public Human
{

};

int main()
{
    Hybrid h;
    h.speak();
    h.sound();
    return 0; 
}