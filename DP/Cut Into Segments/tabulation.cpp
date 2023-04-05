#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int solveMem(int n, int x, int y, int z)
{
    // starting me sabko INT_MIN setup kr do re ya -1 bhi kr skte but phir condn lagani hogi that dp[i-x] != -1 etc for y, z also

    // step1 : dp array create
    vector<int> dp(n + 1, INT_MIN);

    // step2 : check base case
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);

        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);

        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if (dp[n] < 0)
        return 0;

    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    int ans = solveMem(n, x, y, z);
    return ans;
}


//----------------------------------------------------------------------------------------------------------------------------------------------

// int solveMem(int n, int x, int y, int z)
// {
//     // starting me sabko INT_MIN setup kr do re ya -1 bhi kr skte but phir condn lagani hogi that dp[i-x] != -1 etc for y, z also

//     // step1 : dp array create
//     vector<int> dp(n + 1, -1);

//     // step2 : check base case
//     dp[0] = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         if ( i - x >= 0 && dp[i-x] != -1 )
//             dp[i] = max(dp[i], dp[i - x] + 1); // use second condn bc -1+1 = 0 ho jayega and ans 0 aa jayega

//         if (i - y >= 0 && dp[i-y] != -1 )
//             dp[i] = max(dp[i], dp[i - y] + 1);

//         if (i - z >= 0 && dp[i-z] != -1 )
//             dp[i] = max(dp[i], dp[i - z] + 1);
//     }

//     if (dp[n] < 0)
//         return 0;

//     return dp[n];
// }

// int cutSegments(int n, int x, int y, int z)
// {
//     int ans = solveMem(n, x, y, z);
//     return ans;
// }






int main()
{

    return 0;
}