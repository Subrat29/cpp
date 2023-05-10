#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int maxMeetings(int start[], int end[], int n)
{
    // step1: create a vector of pair type
    vector<pair<int, int>> v;

    // step2: insert the start and end time inside it in pair form
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = make_pair(start[i], end[i]);
        v.push_back(p);
    }

    // step3: sort the vector
    sort(v.begin(), v.end(), cmp);

    int count = 1;
    int prevEnd = v[0].second;

    // int prevEnd = end[0]; //this is wrong bc ye always first wala hi lega gfg pr custom test case run kro pta chal jyega. 


    // step4: main logic
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > prevEnd)
        {
            count++;
            prevEnd = v[i].second;
        }
    }
    return count;
}

int main()
{

    return 0;
}