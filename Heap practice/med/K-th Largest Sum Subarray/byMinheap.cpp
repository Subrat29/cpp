#include <bits/stdc++.h>
using namespace std;

int getKthLargest(vector<int> &arr, int k) // sc: O(k) , tc: (n^2) <-maybe less ho?
{
    priority_queue<int, vector<int>, greater<int>> min;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if (min.size() < k)
            {
                min.push(sum);
            }
            else
            {
                if (sum > min.top())
                {
                    min.pop();
                    min.push(sum);
                }
            }
        }
    }
    return min.top();
}

int main()
{

    return 0;
}