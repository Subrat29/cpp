#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n) // tc = O(m*n),   sc = O(m) bc of ans vector;
{
    string ans = "";

    // for traversing all characters of first string
    for (int i = 0; i < arr[0].size(); i++)
    {
        char ch = arr[0][i];
        bool check = true;

        // for comparing ch with rest of the strings
        for (int j = 1; j < n; j++)
        {
            // not match
            if (arr[j].size() < i || ch != arr[j][i])
            {
                check = false;
                break;
            }
        }

        if (check == false)
        {
            break;
        }
        else
        {
            ans.push_back(ch);
        }
    }
    return ans;
}

int main()
{
    return 0;
}