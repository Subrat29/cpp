#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> s;

    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i];

        //if opening bracket then stack push
        //if closing bracket then stacktop check and pop if condn true

        if (ch == '{' || ch == '(' || ch == '[')
        {
            s.push(ch);
        }

        else
        {
            if (!s.empty())
            {
                char top = s.top();
                if ( (ch == ')' && top == '(') ||
                     (ch == '}' && top == '{') ||
                     (ch == ']' && top == '[') )
                {
                    s.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())  // Remember not use '!' in flow   //Note: this condn is use only in valid cases
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string expression = "{[)]}";

    if (isValidParenthesis(expression))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}