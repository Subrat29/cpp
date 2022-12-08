#include <bits/stdc++.h>
using namespace std;

void delete(stack <int>&s, int size)
{

}

    // void deleteMid(stack<char>&s, int sizeOfStack)
    // {
        
    // }

int main()
{
    // stack<char> st;

    // st.push('1');
    // st.push('2');
    // st.push('3');
    // st.push('4');
    // st.push('5');
    // st.push('6');
    // st.push('7');
 
    // deleteMid(st, st.size());

    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    int size = s.size();
    delete(s, size);

    return 0;
}