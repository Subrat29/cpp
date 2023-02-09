#include <bits/stdc++.h> // if there is a 0 base indexing then do this
using namespace std;

void heapify(int arr[], int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;

    if (left <= n && arr[left] < arr[smallest])
    {
        smallest = left;
    }

    if (right <= n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(arr[smallest], arr[i]);
        heapify(arr, n, smallest);
    }
}

int main()
{
    int arr[5] = {50, 51, 49, 53, 54};
    int n = 5;

    // print given array
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // apply heapify algo to build min heap
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // print minHeap
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}