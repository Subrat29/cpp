#include <iostream>
#include <vector>
using namespace std;

//Imp ques by love ask in interview

int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    // base case
    if (index >= n)
        return 0;

    // 1 day pass
    int option1 = cost[0] + solve(n, days, cost, index + 1);

    // 7 day pass
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);             // these ; is very imp ow shows error
    int option2 = cost[1] + solve(n, days, cost, i);

    // 30 day pass
    for (i = index; i < n && days[i] < days[index] + 30; i++);
    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solve(n, days, cost, 0);
}

int main()
{

    return 0;
}