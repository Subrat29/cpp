#include <bits/stdc++.h>
using namespace std;

int findCelebrity(int mat[4][4], int n)
{
    bool celeb = false;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && mat[i][j] == 0 && i != j && mat[j][i] == 1)
            {
                cnt++;
                cout << cnt ;
            }
        }
        if (cnt == n - 1)
        //     celeb = true;
        // if (celeb == true)
            return i;
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
    cout << ans << endl;
    return 0;
}