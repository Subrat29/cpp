#include <bits/stdc++.h> // ImpNote: Maxheap ka use krke smallest elem nikal skte h Minheap ka use krke largest elem
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)  //ok but i dont understand deep reason why this logic run even after dry run??
{
    // step1: create a maxheap
    priority_queue<int> pq;

    // step2: push 0 to k-1 elements in heap;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // step3: push k to n-1 element
    for (int i = k; i <= r; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main()
{

    return 0;
}