#include <bits/stdc++.h>
using namespace std;

int productOfArray(int *arr, int size)
{
    int mul = 1;
    for(int i=0; i<size; i++)
    {
        mul = mul * arr[i];
    }
    return mul;
}

int decTobinary(int n)
{
    int binaryNum[100];
    int i=0;

    while (n>0) 
    {
        binaryNum[i++] = n % 2;
        n = n / 2;
    }
    return i;
}

int main()
{
    int arr[] = {3,2,3};   // this gives size: 3 && int arr[100] = {3,2,3}; gives size: 100
    int size = sizeof(arr)/sizeof(int);
    int mul = productOfArray(arr, size);
    cout << decTobinary(mul);

    return 0;
}


