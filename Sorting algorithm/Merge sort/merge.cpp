#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    // create 2 array for copying values  (find length simple math)
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *first = new int[l1];
    int *second = new int[l2];

    // copy values
    int mainArrayIndex = s;

    for (int i = 0; i < l1; i++)
    {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;                   // what is use of this line if not use then...it also run

    for (int i = 0; i < l2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted array
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < l1 && index2 < l2)
    {
        if (first[index1] < second[index2])
            arr[mainArrayIndex++] = first[index1++];
        else
            arr[mainArrayIndex++] = second[index2++];
    }

    while (index1 < l1)
    {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < l2)
    {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete[] first;
    delete[] second;

}

void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = s + (e - s) / 2;

    // sort left part
    mergeSort(arr, s, mid);

    // sort right part
    mergeSort(arr, mid + 1, e);

    // Now, merge
    merge(arr, s, e);
}

int main()
{
    int arr[] = {4, 5, 4, 3, 2, 1, 4, 3, 4, 3, 4, 3, 4, 5, 5, 6, 4, 4, 44 ,4, 2, 4};  //it work on large inputs but if i try this on other sorting algo they fails

    // int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(int);

    mergeSort(arr, 0, n - 1);

    cout << "Merge Sorting" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}