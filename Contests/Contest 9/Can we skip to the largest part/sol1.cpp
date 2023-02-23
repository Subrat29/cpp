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

    int f = 0;
    for (int i = 0; i < n; i++)
    {
        int subarrSum = 0;
        for (int j = i; j < n; j++)
        {
            subarrSum += arr[j];

            if (subarrSum > arrSum)
                return true;
        }
    }

    return false;
}

int main()
{

    return 0;
}