#include<iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> d;

    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    d.push_back(5);

    d.push_front(0);

    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    d.pop_front();
    d.pop_back();

    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    if(d.empty())
    {
        cout << "Empty" << endl;
    }
    else
    {
        cout << "Not Empty" << endl;
    }
    
    return 0;
}