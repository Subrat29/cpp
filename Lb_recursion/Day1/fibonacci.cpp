#include <bits/stdc++.h>
using namespace std;

int fibo(int n)
{
    //base case
    if(n==0 || n==1)
    {
        return n;
    }
    //recursive call
    int choti = fibo(n-1) + fibo(n-2);
    int badi = choti;
    return badi;
}
int main()
{
    int n;
    cin >> n;
    int ans = fibo(n);
    cout << ans;
    return 0;
}