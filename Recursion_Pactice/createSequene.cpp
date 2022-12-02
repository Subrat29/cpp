#include <bits/stdc++.h>
using namespace std;

bool check(long long n)
{
    while (n != 0)
    {
        long long rem = n % 10;
        if (rem == 2 || rem == 5)
        {
            n = n / 10;
        }
        else
        {
            return false;
        }
    }
    return true;
}

vector<long long> createSequence(long long n)
{
    vector<long long> temp;

    // base case
    if (check(n) == true)
    {
        temp.push_back(n);
    }

    // recursive call
    createSequence(n - 1);
    return temp;
}

int main()
{
    long long n;
    cout << "n: ";
    cin >> n;
    vector<long long> ans = createSequence(n);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}