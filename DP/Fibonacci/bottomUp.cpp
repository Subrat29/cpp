#include <iostream>
#include <vector>
using namespace std;

int fibo(int n, vector<int> &dp)
{
    //step2 : base condn check
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    //step1 : create dp
    vector<int> dp(n + 1);

    cout << fibo(n, dp);

    return 0;
}