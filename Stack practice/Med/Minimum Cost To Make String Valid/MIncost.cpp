#include <bits/stdc++.h>
using namespace std;

int findMinimumCost(string str)
{
    //odd condition
    if (str.length() % 2 == 1)
    {
        return -1;
    }

    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];

        if (ch == '{')
        {
            s.push(ch);
        }

        else  //ch is closed braces
        {
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                s.push(ch);
            }
        }
    }

    //stack contains invalid expression

    int a = 0, b = 0;
    while (!s.empty())
    {
        if(s.top() == '{')
        {
            a++;
        }
        else
        {
            b++;
        }
        s.pop();              //dont forget this
    }

    return (a+1)/2 + (b+1)/2;
}

int main()
{
    string str = "{{{{}}{{";

    cout << findMinimumCost(str) << endl;

    return 0;
}