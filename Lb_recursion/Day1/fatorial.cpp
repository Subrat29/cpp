#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    // for n-1
    int choti = factorial(n-1);

    // for n
    int badi = n * choti;
    return badi;

}

int main()
{
    int n;
    cout << "n: ";
    cin >> n;
    int ans = factorial(n);
    cout << ans;
    return 0;
}