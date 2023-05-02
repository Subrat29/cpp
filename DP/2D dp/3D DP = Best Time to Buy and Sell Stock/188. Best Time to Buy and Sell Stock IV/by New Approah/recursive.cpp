#include <iostream>
#include <vector>
using namespace std;

// New approch : by use of transaction number

int solve(int index, int transactionNo, int k, vector<int> &prices)
{
    // base case
    if (index == prices.size())
        return 0;

    // base case
    if (transactionNo == 2 * k)
        return 0;

    int profit = 0;

    // buy allowed
    if (transactionNo % 2 == 0)
    {
        int buyKaro = -prices[index] + solve(index + 1, transactionNo + 1, k, prices);
        int skipKaro = 0 + solve(index + 1, transactionNo, k, prices);
        profit = max(buyKaro, skipKaro);
    }
    // buy not allowed
    else
    {
        int sellKaro = prices[index] + solve(index + 1, transactionNo + 1, k, prices);
        int skipKaro = 0 + solve(index + 1, transactionNo, k, prices);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}

int maxProfit(int k, vector<int> &prices)
{
    return solve(0, 0, k, prices);
}

int main()
{

    return 0;
}