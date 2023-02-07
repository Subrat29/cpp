#include <bits/stdc++.h>
using namespace std;

// this is little chullad question ques me ho 1st example diya h vo one of the 4 elements h na ki exact answer.

int chooseMaxStudents(vector<int> &h, int n)
{
    sort(h.begin(), h.end());

    int p1 = 0, p2 = 0;
    int ans = 1;
    while (p2 < n) // equal to nhi lege bc elem n-1 tk h bro
    {
        int diff = h[p2] - h[p1];
        if (diff <= 5)
        {
            ans = max(ans, p2 - p1 + 1);
            p2++;
        }
        else
            p1++;
    }
    return ans;
}

int main()
{
    vector<int> h;

    h.push_back(1);
    h.push_back(7);
    h.push_back(13);

    int n = h.size();
    int a = chooseMaxStudents(h, n);

    cout << "ans: " << a << endl;

    return 0;
}