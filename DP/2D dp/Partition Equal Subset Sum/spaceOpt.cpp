#include <iostream>
#include <vector>
using namespace std;

bool solve(int arr[], int N, int total)
{
    vector<int> curr(total + 1, 0);    //total/2 se bhi chal jayega baaki peche walo me bhi bro
    vector<int> next(total + 1, 0);

    // analyse base case
    curr[0] = 1;
    next[0] = 1;

    for (int index = N - 1; index >= 0; index--)
    {
        for (int target = 0; target <= total / 2; target++)
        {
            bool incl = 0;
            if (target - arr[index] >= 0)
                incl = next[target - arr[index]];
            bool excl = next[target];

            curr[target] = incl || excl;
        }
        next = curr;
    }
    return next[total / 2];
}

int equalPartition(int N, int arr[])
{
    int total = 0;
    for (int i = 0; i < N; i++)
        total += arr[i];

    // if odd
    if (total & 1)
        return 0;

    return solve(arr, N, total);
}

int main()
{

    return 0;
}