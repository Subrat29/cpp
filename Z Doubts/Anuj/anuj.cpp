#include <iostream>
#include <vector>
using namespace std;

void reverseInGroups(vector<long long> &arr, int n, int k)
{
    int i = 0;
    int j = k - 1;

    while (j <= n)
    {
        int ii = i;
        int jj = j;
        while (ii <= jj)
        {
            swap(arr[ii++], arr[jj--]);
        }
        i = i + k;
        j = j + k;
    }

    j = n - 1;
    while (i <= j)
    {
        swap(arr[i++], arr[j--]);
    }
}

int main()
{
    vector<long long> arr;

    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(10);
    arr.push_back(11);
    arr.push_back(12);
    arr.push_back(13);
    arr.push_back(14);
    arr.push_back(15);
    arr.push_back(16);

    int n = arr.size();
    int k = 3;

    reverseInGroups(arr, n, k);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}