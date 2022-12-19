#include <bits/stdc++.h>
using namespace std;

vector<int> leftSmaller(int A[], int n) // prev smaller
{
    stack<int> s;
    s.push(0);

    vector<int> left(n);

    for (int i = 0; i < n; i++)
    {
        while (s.top() >= A[i])
        {
            s.pop();
        }
        left[i] = s.top();
        s.push(A[i]);
    }
    return left;
}

vector<int> rightSmaller(int A[], int n) // next smaller
{
    stack<int> s;
    s.push(0);

    vector<int> right(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() >= A[i])
        {
            s.pop();
        }
        right[i] = s.top();
        s.push(A[i]);
    }
    return right;
}

int findMaxDiff(int A[], int n)
{
    vector<int> left = leftSmaller(A, n);
    vector<int> right = rightSmaller(A, n);

    int ans = 0, dif = 0;
    for (int i = 0; i < n; i++)
    {
        dif = left[i] - right[i];
        ans = max(ans, dif);
    }
    return ans;
}

int main()
{
    int A[] = {2, 4, 8, 7, 7, 9, 3};
    int n = sizeof(A) / sizeof(int);

    cout << findMaxDiff(A, n) << endl;

    return 0;
}