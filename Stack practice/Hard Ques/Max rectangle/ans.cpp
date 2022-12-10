#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<int> nextSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int curr = arr[i];
        while (s.top() != -1 && arr[s.top()] >= curr)
        {
            s.pop();
        }

        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(int *heights, int n)
{
    vector<int> next(n);
    next = nextSmallerElement(heights, n);

    vector<int> prev(n);
    prev = prevSmallerElement(heights, n);

    int area = INT_MIN;                //mistake i use INT_MAX then what consequences??
    for (int i = 0; i < n; i++)
    {
        int l = heights[i];

        if (next[i] == -1)
        {
            next[i] = n;
        }

        int b = next[i] - prev[i] - 1;

        int newArea = l * b;
        area = max(area, newArea);
    }
    return area;
}

int maxArea(int M[MAX][MAX], int n, int m)
{
    // compute area for first row
    int area = largestRectangleArea(M[0], m);      // i use n inplace m

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // row update: by adding prev row value
            if (M[i][j] != 0)
                M[i][j] = M[i][j] + M[i - 1][j];

            else
                M[i][j] = 0;
        }

        // entire row is updated now
        area = max(area, largestRectangleArea(M[i], m));
    }
    return area;
}

int main()
{
    int M[MAX][MAX];

    int n = 4;
    int m = 4;
    M[n][m] = {{0, 1, 1, 0},
               {0, 0, 0, 1},
               {1, 1, 0, 1},
               {1, 1, 1, 0}};

    cout << maxArea(M, n, m) << endl;

    return 0;
}