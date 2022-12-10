#include <bits/stdc++.h>
using namespace std;

int findCelebrity(int mat[4][4], int n)          //Not work, not pass all test cases 
{
    bool celeb = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if( (mat[i][j] == 0) && ( i!=j && mat[j][i] == 1) )
            {
                celeb = true;
                cout << "i : " << i << "  j : " << j << "  celeb : " << celeb <<endl;
            }
        }

        if(celeb == true)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int n = 4;
    int mat[4][4] = {{0, 1, 1, 0},
                    {0, 0, 0, 1},
                    {1, 1, 0, 1},
                    {1, 1, 1, 0}};

    int ans = findCelebrity(mat, n);
    cout << ans;

    return 0;
}