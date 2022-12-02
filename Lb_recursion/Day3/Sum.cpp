#include <bits/stdc++.h>
using namespace std;

int findsum(int a[], int size)
{
    //base case
    if(size == 0)
    return 0; 

    //Assume u got it for n-1 
    int remainingpart_sum = findsum(a+1,size-1);
    int full_sum = a[0] + remainingpart_sum;

    return full_sum;
}

int main()
{
    int a[4] = {1,3,4};
    int size = 4;
    int ans = findsum(a,size);
    cout << ans;
    return 0;
}

//TRYING PART -->
 
/*#include <bits/stdc++.h>
using namespace std;

int findsum(int a[], int size, int sum)
{
    if(size == 0)
    return 0;

    sum = sum + a[0];
    findsum(a+1, size-1, sum);

    return sum;
}

int main()
{
    int a[4] = {1,4,5,6};
    int size = 4;
    int sum = 0;
    int ans = findsum(a,size, sum);
    cout << ans;
    return 0;
} */