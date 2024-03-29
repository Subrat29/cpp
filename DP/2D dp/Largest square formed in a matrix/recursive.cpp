#include <iostream>
#include <vector>
using namespace std;

int solve(vector<vector<int>> mat, int i, int j, int &maxi)
{
    // way to find out row & col in 2d vector
    if (i >= mat.size() || j >= mat[0].size())
    {
        return 0;
    }

    int right = solve(mat, i, j + 1, maxi);
    int down = solve(mat, i + 1, j, maxi);
    int diagonal = solve(mat, i + 1, j + 1, maxi);

    if (mat[i][j] == 1)
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int maxi = 0;
    solve(mat, 0, 0, maxi);
    return maxi;
}

int main()
{

    return 0;
}