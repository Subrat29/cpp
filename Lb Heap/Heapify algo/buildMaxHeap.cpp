#include<iostream>
using namespace std;

// tc: O(nlogn)

void heapify(int arr[], int n, int i) 
{ 
    int largest = i;
    int leftChild = 2 * largest;
    int rightChild = 2 * largest + 1;

    if (leftChild <= n && arr[leftChild] > arr[largest])  //remember <=
    {
        largest = leftChild;
    }

    if (rightChild <= n && arr[rightChild] > arr[largest])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

//for 1 based indexing
int main()  
{
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    //print given array
    cout << "Array: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    //heapify algo
    for (int i = n / 2; i > 0; i--)  // tc: O(n) for building heap
    {
        heapify(arr, n, i);
    }

    //print maxheap
    cout << "After heapify: ";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
