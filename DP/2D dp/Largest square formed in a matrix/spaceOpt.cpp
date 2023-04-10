 #include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>> &mat, int &maxi)
{
    //no need of dp array bc dp[i][j] depend on curr & next row only see copy

    int row = mat.size();
    int col = mat[0].size();

    vector<int> curr(col+1, 0);
    vector<int> next(col+1, 0);
    
    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 0; j--)
        {
            int right = curr[j + 1];
            int down = next[j];
            int diagonal = next[j + 1];

            if (mat[i][j] == 1)
            {
                curr[j] = 1 + min(right, min(diagonal, down));
                maxi = max(curr[j], maxi);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
  
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int maxi = 0;
    solve(mat, maxi);
    return maxi;
}

int main()
{

    return 0;
}