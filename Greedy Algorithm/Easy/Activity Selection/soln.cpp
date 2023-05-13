#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> &s, vector<int> &e, int n)
{
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++)
    {
        p[i].first = e[i];
        p[i].second = i;
    }

    sort(p.begin(), p.end());

    int prevEnd = p[0].first;
    int count = 1;

    for (int i = 0; i < n; i++)
    {
        if (s[p[i].second] > prevEnd)
        {
            count++;
            prevEnd = p[i].first;
        }
    }
    return count;
}

int activitySelection(vector<int> start, vector<int> end, int n)
{
    return solve(start, end, n);
}

int main()
{

    return 0;
}