#include <bits/stdc++.h>
using namespace std;

int getMaxArea(int hist[], int n)
{
    int Newarea = 0;
    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i;
        int r = i;

        while (hist[l] > hist[i] && l > 0)
        {
            l--;
        }

        while (hist[r] > hist[i] && r < n )
        {
            r++;
        }  

        Newarea = (r-l+1) * hist[i];
        area = max(Newarea, area);
        cout << "r : " << r << "   l : " << l << endl;
        cout << "New Area : " << Newarea << "   Max Area : " << area << endl << endl;
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