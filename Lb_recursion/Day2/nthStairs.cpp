#include<iostream>
using namespace std;

int nthStairs(int n)
{
    //base case
    if(n<0)
    {
        return 0;
    }

    if(n==0)
    {
        return 1;
    }   
    
    //recursive call
    return nthStairs(n-1) + nthStairs(n-2);
}

int main()
{
    int n;
    cin >> n;
    int ans = nthStairs(n);
    cout << ans;
    return 0;
}