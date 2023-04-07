#include <iostream>
#include <vector>
#define MOD 1000000007

//tc - o(1) 
long long int solve(int n)
{
    // step 1
    long long int prev2 = 0;
    long long int prev1 = 1;

    // step 3: convert recursive call into dp relation
    // upar 2 case solve kr liye h to 3 case se start hoga maam
    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;
        long long int sum = (first + second) % MOD;

        long long int ans = ((i-1) * sum) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;  //we can also return ans but ans ka scope loop ke inside hi h thats why return prev1 
}

long long int countDerangements(int n)
{
    return solve(n);
}

int main()
{

    return 0;
}