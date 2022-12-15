#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    unordered_map<char, int> count;
    string ans = "";                                //initialise
    queue<int> q;

    for (int i = 0; i < A.length(); i++)
    {
        char ch = A[i];
        q.push(ch);
        count[ch]++;

        while (!q.empty())
        {
            if (count[q.front()] > 1)
            {
                q.pop();
            }
            else
            {
                ans.push_back(q.front());
                break;                                  //forget break;
            }
        }

        if (q.empty())
        {
            ans.push_back('#');
        }
    }

    return ans;
}

int main()
{
    string A = "aabc";
    cout << FirstNonRepeating(A);

    return 0;
}