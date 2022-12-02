#include <bits/stdc++.h>
using namespace std;

int powerof2(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    //n-1
    int choti = powerof2(n-1);
    int badi = 2*choti;
    return badi;
}

int main()
{
    int n;
    cin >> n;
    int ans = powerof2(n);
    cout << ans;
    return 0;
}