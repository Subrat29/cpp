#include <iostream>
using namespace std;

#define MOD 1000000007

long long int countDerangements(int n)
{
    // base case
    if (n == 1)
        return 0;

    if (n == 2)
        return 1;

    int ans = ( (n - 1) * (countDerangements(n - 1) + countDerangements(n - 2)) ) % MOD;

    return ans;
}

int main()
{

    return 0;
}