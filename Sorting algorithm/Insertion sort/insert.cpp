#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;

        for (; j >= 0; j--)
        {
            if (arr[j] > temp)                 //yha ye dalne ke bad ek aur traverse krega where it not satisfy then break to j ek aage pahuch jayegi always
                arr[j + 1] = arr[j];  //1 shift kr diya 
            else
                break;
        }

        arr[j + 1] = temp;             //Now jagah khali ho gyi to ab temp daal dege...upar explain kra h
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);

    cout << "Insertion Sorting"<< endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}