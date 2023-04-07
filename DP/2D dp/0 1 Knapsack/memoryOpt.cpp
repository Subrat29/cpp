// No need to make 2D array our work done by 2 arrays also bc nth row depend on only n-1th row not full 2d vector
//every row only depend upon previous row only
// sc : O(2*maxweight)

#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // step1 : create array
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    // step2 : analyse base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }

    // step3: 
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + prev[w - weight[index]];

            int exclude = 0 + prev[w];

            curr[w] = max(exclude, include);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n, maxWeight);
}

int main()
{

    return 0;
}