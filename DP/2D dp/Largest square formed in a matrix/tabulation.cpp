#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int m, vector<vector<int>> &mat, int &maxi)
{

    // step1 : create dp array
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // step2 : base cases
    // no need of base case because phle se hi hm bottom se up ja rhe h n-1 se 0, compare it with memo base case

    // step3 : convert recursive call in dp
    // we start from n-1 but in diagonal and etc we use i+1 & j+1 jisse hm array ke bahar chle jayege thats why +1 in dp vector
    
    
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int down = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];

            if (mat[i][j] == 1)
            {
                dp[i][j] = 1 + min(right, min(diagonal, down));
                maxi = max(dp[i][j], maxi);
                dp[i][j];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
  
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int maxi = 0;
    solve(n, m, mat, maxi);
    return maxi;
}

int main()
{

    return 0;
}