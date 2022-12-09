#include <bits/stdc++.h>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }

        else // ch ya toh ')' hai or lowercase letter & we ignore letters
        {
            if (ch == ')')
            {
                bool isReductant = true;

                while (st.top() != '(')
                {
                    char top = st.top();
                    if (top == '+' || top == '-' || top == '*' || top == '/')
                    {
                        isReductant = false;
                    }
                    st.pop();
                }

                if (isReductant == true)
                {
                    return true;
                }
                st.pop();                  //ye pop opening bracket ko pop krne ke liye h , st.top() == '(' pr while ke andr nhi ja payege
            }
        }
    }
    return false;
}

int main()
{
    string s = "((a+b)-u)";
    if (findRedundantBrackets(s))
    {
        cout << "Reductant" << endl;
    }
    else
    {
        cout << "Not reductant" << endl;
    }

    return 0;
}