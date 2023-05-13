#include <iostream>
#include <queue>
using namespace std;

long long minCost(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> h;

    for (int i = 0; i < n; i++)
    {
        h.push(arr[i]);
    }

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