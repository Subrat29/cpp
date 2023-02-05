#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) // max heap : 0 base indexing
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;

    while (size > 0)
    {
        swap(arr[0], arr[size]);
        size--;

        heapify(arr, size, 0);
    }
}

int kthSmallest(int arr[], int l, int r, int k)  // tc = O(nlogn);
{
    
    // int doubt = (r / 2) - 1;   // By me: not run in this input, it lack for some input bc size phle se size-1 diya if we did -1 then it wrong.
    int doubt = r / 2;            // thats why it run


    for (int i = doubt; i >= 0; i--)    // tc: O(n) for building heap
    {
        heapify(arr, r, i);
    }

    heapsort(arr, r);

    return arr[k - 1];
}

int main()
{
    int arr[] = {571, 600, 134, 32, 52, 376, 108, 29, 500, 533, 684, 422};
    // int arr[] = {54, 53, 55, 52, 50};

    int size = sizeof(arr) / sizeof(int);
    int r = size - 1;
    int k = 7;

    cout << endl
         << "Before: ";
    for (int i = 0; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << k << " smallest elem is: " << kthSmallest(arr, 0, r, k) << endl;

    cout << "After: ";
    for (int i = 0; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl
         << endl;

    return 0;
}