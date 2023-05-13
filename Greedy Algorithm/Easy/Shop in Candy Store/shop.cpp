#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//sc = 1
//tc = nlogn bc of sort

vector<int> candyStore(int candies[], int N, int K)
{
    sort(candies, candies + N);

    // Minimum money nikalne ke liye, buy ko aage se chlaoo, free ko peeche se
    int buy = 0;
    int mini = 0;
    int free = N - 1;

    while (buy <= free)
    {
        mini = mini + candies[buy];
        buy++;
        free = free - K;
    }

    // Maximum money nikalne ke liye, buy ko aage se chlaoo, free ko peeche se
    int maxi = 0;
    buy = N - 1;
    free = 0;

    while (buy >= free)
    {
        maxi = maxi + candies[buy];
        buy--;
        free = free + K;
    }

    // vector<int> ans(2); Wrong : ye 0,0 output dera h 

    vector<int> ans(2);
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;
}

int main()
{

    return 0;
}