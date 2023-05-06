#include <iostream>
#include < vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> nextSmallerElement(vector<int> arr, int n)
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

    vector<int> prevSmallerElement(vector<int> arr, int n)
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

    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN; // area = 0;  this also use
        for (int i = 0; i < n; i++)
        {
            int l = heights[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;

            int newArea = l * b;

            area = max(newArea, area);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>> &matrix)
    {
        // Note: bc idhr 2d matrix h, therefore max of all areas nikalna padega jo aaye h
        int maxi = INT_MIN;

        vector<int> histogram(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < histogram.size(); j++)
            {
                if (matrix[i][j] == '1')
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }
            maxi = max(maxi, largestRectangleArea(histogram));
        }
        return maxi;
    }
};