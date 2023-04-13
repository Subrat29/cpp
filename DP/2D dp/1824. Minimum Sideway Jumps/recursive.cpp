#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &obstacles, int currlane, int currpos)
{
    int n = obstacles.size();

    // base case
    if (currpos == n)
        return 0;

    // if no obstacle on current lane
    if (obstacles[currpos + 1] != currlane)
    {
        return solve(obstacles, currlane, currpos + 1);
    }
    // if obstacle present on current lane
    else
    {
        // sideways jump
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currlane != i && obstacles[currpos] != i)
                ans = min(ans, 1 + solve(obstacles, i, currpos));
        }
        return ans;
    }
}

int minSideJumps(vector<int> &obstacles)
{
    return solve(obstacles, 2, 0);
}

int main()
{

    return 0;
}