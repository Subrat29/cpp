#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
{
    vector<pair<int, int>> p(N);

    for (int i = 0; i < N; i++)
    {
        p[i].first = F[i];
        p[i].second = i;
    }

    sort(p.begin(), p.end());

    vector<int> ans;
    ans.push_back(p[0].second+1);

    int prevEnd = p[0].first;

    for (int i = 0; i < N; i++)
    {
        if (S[p[i].second] > prevEnd)
        {
            prevEnd = p[i].first;
            ans.push_back(p[i].second+1);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{

    return 0;
}