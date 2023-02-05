#include <bits/stdc++.h> //for 0 base indexing
using namespace std;

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    // step1: merge 2 max heap randomly
    for (int i = 0; i < m; i++)
    {
        a.push_back(b[i]);
    }

    // step2: build it max heap
    n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    return a;
}

int main()
{
    return 0;
}