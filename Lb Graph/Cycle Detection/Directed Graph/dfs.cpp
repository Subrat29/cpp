#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

bool checkCycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    dfsVisited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            if (checkCycleDFS(neighbour, visited, dfsVisited, adj))
                return true;
        }
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }

    // call dfs for all component
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (checkCycleDFS(i, visited, dfsVisited, adj))
            return true;
        }
    }
    return false;
}

int main()
{

    return 0;
}