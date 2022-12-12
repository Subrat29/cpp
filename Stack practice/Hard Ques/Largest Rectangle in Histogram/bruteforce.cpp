#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n)   //this works but shows tle in large test case so pls optimize it.
{
    int Newarea = 0;
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i;
        int r = i;

        while (l >= 0 && hist[l] >= hist[i] )
        {
            l--;
        }

        while ( r < n && hist[r] >= hist[i] )
        {
            r++;
        }  

        Newarea = (r-l-1) * hist[i];
        area = max(Newarea, area);
    }

    return area;
}

int main()
{

    int hist[] = {2,1,5,6,2,3};
    int n = sizeof(hist) / sizeof(hist[0]);

    // Function call
    cout << "Maximum area is " << getMaxArea(hist, n);

    return 0;
}