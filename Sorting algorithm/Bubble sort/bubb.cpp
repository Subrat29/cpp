#include <iostream>
using namespace std;

// last part remove in every round

void bubbleSort(int arr[], int n)
{
    for (int i = 1; i < n; i++) // n-1 rounds // use only for no. of rounds
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
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



//For Dry Run Only

// void bubbleSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i++) // n-1 rounds // use only for no. of rounds
//     {
//         for (int j = 0; j < n - i; j++)
//         {
//             cout << "i : " << i << ",  j : " << j;
//             cout << "  arr[j] = " << arr[j] << "  arr[j+1] = " << arr[j + 1] << endl;

//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//                 cout << "---> swap" << endl;
//             }
//             for (int i = 0; i < 6; i++)
//             {
//                 cout << arr[i] << " ";
//             }cout << endl << endl;
//         }
//         cout << endl;
//     }
// }