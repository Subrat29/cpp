#include <iostream>
#include <vector>
using namespace std;

//by using only one vector
//sc : O(maxWeight)

//right to left --> value not overwrite therefore give correct answer
//left to right --> value overwrite therefore give wrong answer

int solve(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{
    // step1 : create array
    vector<int> curr(maxWeight + 1, 0);

    // step2 : analyse base case
    for (int w = weight[0]; w <= maxWeight; w++)
    {
        if (weight[0] <= maxWeight)
            curr[w] = value[0];
        else
            curr[w] = 0;
    }

    // step3:  
    for (int index = 1; index < n; index++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int include = 0;

            if (weight[index] <= w)
                include = value[index] + curr[w - weight[index]];

            int exclude = 0 + curr[w];

            curr[w] = max(exclude, include);
        }
    }
    return curr[maxWeight];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n, maxWeight);
}

int main()
{

    return 0;
}