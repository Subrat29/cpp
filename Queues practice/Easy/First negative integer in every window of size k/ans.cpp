#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int A[],
                                            long long int N, long long int K)         //first time: very confusing ques
{
    deque<long long int> dq;
    vector<long long> ans;

    // process 1st window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }

    // Push answer of 1st window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // Now process remaining windows
    for (int i = K; i < N; i++)
    {
        // pop out 1st window element
        if (!dq.empty() && (i - dq.front()) >= K)       //Reason 4 use: To check dq.front() current wali k size ki window me aati h ya nhi aati
        {
            dq.pop_front();
        }

        // then push current element
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        // put in ans
        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
                                                      // Mistake: idhr return krwa diya tha
    }
    return ans;
}

int main()
{
    long long int A[5] = {-8, -2, -3, -6, -10};
    long long int N = 5;
    long long int K = 2;
    vector <long long> ans = printFirstNegativeInteger(A, N, K);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    

    return 0;
}