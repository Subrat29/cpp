#include <iostream>
#include <vector>
using namespace std;
// Not pass 6/8 case on code studio
// tc = O(n)
// sc = O(n)

int solve(vector<int> &v)
{
    int n = v.size();
    long long int prev1 = v[0];
    long long int prev2 = 0;

    for (int i = 1; i < n; i++) // i = 1 se start bc upar prev1 me v[0] dal diye h
    {
        long long int incl = prev2 + v[i];
        long long int excl = prev1 + 0;
        long long int ans = max(incl, excl);

        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    // additional case
    if (n == 1)
        return valueInHouse[0];

    vector<int> first, second;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            first.push_back(valueInHouse[i]);

        if (i != n - 1)
            second.push_back(valueInHouse[i]);
    }

    return max(solve(first), solve(second));
}

int main()
{

    return 0;
}