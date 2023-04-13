#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &Satisfaction, int index, int time)
{
    // base case
    if (index == Satisfaction.size())
        return 0;

    int include = Satisfaction[index] * (time + 1) + solve(Satisfaction, index + 1, time + 1);
    int exclude = 0 + solve(Satisfaction, index + 1, time);

    return max(include, exclude);
}

int maxSatisfaction(vector<int> &satisfaction)
{
    // first sort the array to get maxm ans
    sort(satisfaction.begin(), satisfaction.end());
    return solve(satisfaction, 0, 0);
}

int main()
{

    return 0;
}