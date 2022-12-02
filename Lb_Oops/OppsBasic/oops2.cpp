#include <bits/stdc++.h>
using namespace std;

//Inheritance
class Human
{
    public:
    int height;
    int weight;
    int age;

    public:
    int getage()
    {
        return this->age;
    }
    
    void setWeight(int w)
    {
        this->weight = w;
    }

};

class Male: private Human
{
    public:
    string color;

    void sleep()
    {
        cout<<"male is   sleep"<<endl;
    }

    int getHeight()
    {
        return this->height;
    }
};

int main()
{

    Male m1;
    cout << m1.getHeight() << endl;



/*
    //Inheritance
    Male m1;
    cout << m1.height << endl;
    cout << m1.weight << endl;
    cout << m1.age << endl;
    cout << m1.color << endl;
    m1.sleep();
    m1.setWeight(34);
    cout << m1.weight << endl;
*/
    
    return 0;
}