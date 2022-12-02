#include <bits/stdc++.h>
using namespace std;

int isSorted(int *arr, int size)
{
    // base case
    if (size == 1)
        return true;

    if (arr[0] > arr[1])
        return false;
    else
        isSorted(arr + 1, size - 1);
}
int main()
{
    int a[4] = {1,4,5,6};
    int size = 4;

    if (isSorted(a, size))

        cout << "Sorted";
    else
        cout << "Not sorted";

    return 0;
}