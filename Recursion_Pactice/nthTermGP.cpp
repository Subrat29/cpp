#include <bits/stdc++.h>
using namespace std;

int findgp(long long int n, long long int a, long long int r)
{
    if(n<=0)
    return 0;

    if(n==1)
    return a;

    int chotti = findgp(n-1,a,r);
    int badi = chotti*r;
    return badi;
}

int main()
{
    long long int n = 34;
    //cout << "n: " << endl; 
    cin >> n;
    long long int a = 17;
    //cout << "a: " << endl; 
    long long int r = 13;
    //cout << "r: " << endl; 

    long long int ans = findgp(n,a,r);
    cout << ans << endl;

    return 0;
}