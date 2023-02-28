#include <iostream>
#include <stack>
using namespace std;

int main()
{
    // creation of stack
    stack<int> s;

    // stack push
    s.push(3);
    s.push(4);
    s.push(5);

    // stack pop
    s.pop();

    // print
    cout << s.top() << endl;

    // size of stack
    cout << s.size() << endl;

    // is empty
    cout << s.empty() << endl;

    return 0;
}