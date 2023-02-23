#include <iostream>
#include <vector>
using namespace std;

int largePart(int n, vector<int> arr)
{
    int arrSum = 0;
    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }

    int runSum = 0;
    int largeSum = 0;
    for (int i = 0; i < n; i++)
    {
        runSum = max(0, runSum);
        runSum += arr[i];
        largeSum = max(runSum, largeSum);
    }

    if (largeSum > arrSum)
        return true;
    else
        return false;
}

int main()
{

    return 0;
}