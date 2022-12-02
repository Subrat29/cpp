#include <bits/stdc++.h>
using namespace std;

bool find(int a[], int key, int s, int e)
{
    //base case
    if(s>e)
    {
        return false;
    }

    int mid = s+(e-s)/2;
    if(key==a[mid])
    {
        cout<<"Pos: "<<mid<<endl;
        return true;
    }

    if(a[mid]>key)
    {
        s=mid+1;
    }
    else
    {
        e=mid-1;
    }

    return find(a,key,s,e);
}

int main()
{
    int key;
    cin >> key;
    int a[5] = {5,4,3,2,1};  // DECREASING ORDER 
    int size = 5;
    if(find(a,key,0,size-1))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    return 0;
}