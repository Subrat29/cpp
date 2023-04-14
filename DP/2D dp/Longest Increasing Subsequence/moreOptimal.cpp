#include <iostream>
#include <vector>
using namespace std;

// Now, complexities are match acc to ques
// tc - O(nlogn)
// sc - O(n)

int solveOptimal(int n, int a[])
{
    if (n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(a[0]);

    for (int i = 1; i < n; i++)
    {
        if (a[i] > ans.back())
            ans.push_back(a[i]);

        else
        {
            // find index of just bada element in ans vector
            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        }
    }
    return ans.size();
}

int longestSubsequence(int n, int a[])
{
    return solveOptimal(n, a);
}

int main()
{

    return 0;
}