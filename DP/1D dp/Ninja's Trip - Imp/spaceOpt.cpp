#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//sc = O(1) 
//bc months are 30 and week are 7 toatal - 37


//see copy for more details
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    int ans = 0;

    // pair = day, cost
    queue<pair<int, int>> month;
    queue<pair<int, int>> week;

    for (int day : days)
    {
        // step1: remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
        {
            month.pop();
        }

        while (!week.empty() && week.front().first + 7 <= day)
        {
            week.pop();
        }

        // step2: add cost for current day
        week.push(make_pair(day, ans + cost[1]));
        month.push(make_pair(day, ans + cost[2]));

        // step3: ans update
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}

int main()
{

    return 0;
}