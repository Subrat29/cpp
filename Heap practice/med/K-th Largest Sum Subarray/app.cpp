#include <bits/stdc++.h> // Note: this is very chullad ques kya sum lena h ye hi samaj nhi aaya??
using namespace std;

int getKthLargest(vector<int> &arr, int k)   //sc: O(n^2), tc: O(n^2)
{
    vector<int> v;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            v.push_back(sum);
        }
    }

    sort(v.begin(), v.end());

    return v[v.size() - k];
}

int main()
{

    return 0;
}