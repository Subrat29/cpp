#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &M, int a, int b)
{
    if (M[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int celebrity(vector<vector<int>> &M, int n)
{
    stack<int> s;

    // Step 1: push all person in stack
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }

    // Step 2: take 2 person from stack & check, push who not know other person
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(M, a, b))   //if a knows b
        {
            s.push(b);
        }
        else                 //if b knows a
        {
            s.push(a);
        }
    }

    int ans = s.top(); // Now, we found a potential candidate


    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if(M[ans][i] == 0)
        zeroCount++;
    }

    if(zeroCount != n)
    return -1;

    int oneCount = 0;
    for (int i = 0; i < n; i++)
    {
        if(M[i][ans] == 1)
        oneCount++;
    }

    if(oneCount != n-1)
    return -1;

    return ans;
}

int main()
{
    vector<vector<int>> M;
    M = {{0, 1, 1, 0},
         {0, 0, 0, 1},
         {1, 1, 0, 1},
         {1, 1, 1, 0}};

    int n = M.size();

    int ans = celebrity(M, n);
    cout << ans;

    return 0;
}