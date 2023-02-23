#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) // n = no. of nodes
{
    // adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1; // bc nodes starts from 1
        int v = edges[i].second - 1;
        adj[u].push_back(v);
    }

    // find all indegrees
    vector<int> indegree(n);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    // push 0 indegree wale
    queue<int> q;
    for (int i = 0; i < n; i++) // or i=1 to i<=n use bc here node starts from 1
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs
    int count = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // inc count
        count++;

        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if (count == n)
        return false;
    else
        return true;
}

int main()
{

    return 0;
}