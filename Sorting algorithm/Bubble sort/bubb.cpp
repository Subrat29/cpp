#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) // n-1 rounds
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main()
{
    int arr[] = {10, 1, 7, 6, 14, 9};
    int size = sizeof(arr) / sizeof(int);

    bubbleSort(arr, size);

    cout << "Bubble sorting" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}