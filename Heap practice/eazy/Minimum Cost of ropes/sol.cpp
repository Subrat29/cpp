#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)   //dont forget long long
{
    // step1: create a min heap and insert all elem into it
    priority_queue<long long, vector<long long>, greater<long long>> h;

    for (int i = 0; i < n; i++)
    {
        h.push(arr[i]);
    }

    // step2: pick two min elem from heap and sum them and again push into heap till heap size > 1
    long long ans = 0;
    while (h.size() > 1)
    {
        long long a = h.top();
        h.pop();

        long long b = h.top();
        h.pop();

        long long sum = a + b;
        ans = ans + sum;
        h.push(sum);
    }
    return ans;
}

int main()
{

    return 0;
}