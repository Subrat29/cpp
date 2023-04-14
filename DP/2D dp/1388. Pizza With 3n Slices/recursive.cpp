#include <iostream>
#include <vector>
using namespace std;

int solve(int index, int endIndex, vector<int> &slices, int n)
{
    // base case
    if (n == 0 || index > endIndex)
        return 0;

    int take = slices[index] + solve(index + 2, endIndex, slices, n - 1);
    int notTake = 0 + solve(index + 1, endIndex, slices, n);

    return max(take, notTake);
}

int maxSizeSlices(vector<int> &slices)
{
    int k = slices.size();

    // eat
    int case1 = solve(0, k - 2, slices, k / 3);

    // not eat
    int case2 = solve(0, k - 1, slices, k / 3);

    return max(case1, case2);
}

int main()
{

    return 0;
}