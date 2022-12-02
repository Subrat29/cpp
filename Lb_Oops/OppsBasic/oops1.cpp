#include <bits/stdc++.h>
using namespace std;

class Hero
{
    /*     properties
     string s;    size - 24
     int n;       size - 4
     char c;      size - 1
     double d;    size - 8
     float f;     size - 4  */


// Manually Constructor
public:
    Hero()
    {
        cout << "constructor Called bro" << endl;
        name = new char[100];
    }


// Parameterised Constructor----------------------
public:
    Hero(int health)
    {
        cout << "address of this: " << this << endl;
        this -> health = health;
    }


    Hero(int health, char level)
    {
        this -> health = health;
        this -> level = level;
    }
    
//-------------------------------------------------   

/*
 // Copy Constructor
    Hero (Hero &temp)  // & -> Error if u forget this
    {
        this->health = temp.health;
        this->level = temp.level;
    } 
*/

//Copy Constructor (Deep Copying)
    Hero (Hero &h3)  // & -> Error if u forget this
    {
        char *ch =new char[strlen(h3.name)+1];
        strcpy(ch,h3.name);
        this->name = ch;
        this->health = h3.health;
        this->level = h3.level;
    } 

public:
    char *name;
    int health;
    char level;
    static int timeTocomplete;

    int getHealth()
    {
        return health;
    }

    int getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(int l)
    {
        level = l;
    }

    void print()
    {
        cout << this->name << endl;
        cout << this->health << endl;
        cout << this->level << endl;
    }

    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    //Static function // access only static members
    static int random(){
        return timeTocomplete;
    }

// DESTRUCTOR CALLING (MANUALLY)
    ~Hero(){
        cout<<"Destructor Called"<<endl;
    }

};

int Hero::timeTocomplete = 6; // Static Keyword 

int main()
{
    // creation of object || basics of oops || Access of modifiers || Getter & Setter

    /*
        Hero h1;

        h1.health = 45;
        h1.level = 'r';
        cout << h1.health << endl;
        cout << h1.level << endl;

        cout << h1.getHealth() << endl;
        cout << h1.getLevel() << endl;

        Hero ram;
        ram.setHealth(34);
        ram.setLevel('r');

        cout << ram.getHealth() << endl;
        cout << ram.getLevel() << endl;

    */

    /* // Dynamic allocation

    //Static allocate
    Hero a;
    a.health = 45;
    a.level = 'r';
    cout << a.level << endl;
    cout << a.health << endl;

    //Dynamic allocate
    Hero *b = new Hero;
    b->health = 4765;
    b->level = 'h';

    cout << (*b).level << endl;
    cout << (*b).health << endl;

    cout << b->level << endl;
    cout << b->health << endl;

    */

/*
    // Constructors 
    cout << "hii" << endl;
    Hero komal;
    cout << "hii" << endl;

    // Parameterised constructor
    Hero ramesh(12);
    cout <<"address of ramesh: "<<&ramesh<<endl;  //addr of this keyword ramesh is same

    Hero h(22,'y');
    cout << "Health: " << h.getHealth() << endl;
    h.print();
*/

/*
// Copy Constructor

Hero h1(23,'b');
h1.print();

Hero h2(h1);
h2.print();

*/

/*
//Dynamically name copy 
//By Default copy constructor

Hero h3;
h3.setHealth(78);
h3.setLevel('z');
char name[5] = "King";
h3.setName(name);
//h3.print();

Hero h4(h3);
//h4.print();

//h4.name[0] = 'L';
h4.print();
h3.print();

h3.name[0] = 'L';
h4.print();
h3.print();
*/

/*
//Copy Assignment Operator
Hero h3;
char name[5] = "King";
h3.setName(name);
h3.setHealth(78);
h3.setLevel('z');

Hero h4(h3);
h4.name[0] = 'L';

h3.print();
h4.print();

h3 = h4;
h3.print();
h4.print();
*/

/*
//          Destructor 
//Static
Hero a;
//Dynamic
Hero *b = new Hero();
delete b; 
*/

 
// Static Keyword / Static function
//cout << Hero::timeTocomplete << endl;
//cout << Hero::random()<<endl;

    return 0;
} 