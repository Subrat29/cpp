#include <bits/stdc++.h>
using namespace std;

bool find(int a[], int size, int key, int cnt)
{
    //base case
    if(size==0)
    {
        return false;
    }

    if(a[0]==key)
    {
        cout<<"Pos : "<<cnt<<endl;
        return true;
    }
    
    return find(a+1,size-1,key,cnt+1);
}

int main()
{
    int key;
    cin >> key;
    int a[5] = {1,4,2,5,7};
    int size = 5;
    int cnt = 0;
    if(find(a,size,key,cnt))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not Found"<<endl;
    }

    return 0;
}