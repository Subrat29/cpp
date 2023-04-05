#include <iostream>
#include <vector>
using namespace std;

// Doubts: 
// why dist size n+1 = bc 0 is not in graph 
// 1e9 not int max
// how it run n-1 times = start from 1 bc zero not given in graph && second it also run i=1 to i<n which is n-1 times

//sc = O(n*m)


int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    // step 1: apply formula n-1 times
    for (int i = 1; i <= n; i++)                          // how it run n-1 times ????
    {
        // traverse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // step 2: check for -ve cycle
    int flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && dist[u] + wt < dist[v])
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}

int main()
{

    return 0;
}