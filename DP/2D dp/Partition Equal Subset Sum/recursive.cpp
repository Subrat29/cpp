#include <iostream>
using namespace std;

bool solve(int index, int arr[], int N, int target)
{
    // base case
    if (index >= N)
        return 0;
    if (target < 0)
        return 0;
    if (target == 0)
        return 1;

    // index++ gives error so dont use it
    bool incl = solve(index + 1, arr, N, target - arr[index]);
    bool excl = solve(index + 1, arr, N, target);

    return incl || excl;
}

int equalPartition(int N, int arr[])
{
    int total = 0;
    for (int i = 0; i < N; i++)
        total += arr[i];

    // if odd
    if (total & 1)
        return 0;

    // if even
    int target = total / 2;
    return solve(0, arr, N, target);
}

int main()
{

    return 0;
}