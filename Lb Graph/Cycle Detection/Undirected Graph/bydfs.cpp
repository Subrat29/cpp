#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

bool iscylicDFS(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &visited)
{
    visited[node] = true;

    for (auto neighbour: adj[node])
    {
        if (!visited[neighbour])
        {
            if (iscylicDFS(neighbour, node, adj, visited))
                return true;
        }
        else if (neighbour != parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m) //  n = node , m = edge
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)          //m not n
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscylicDFS(i, -1, adj, visited))
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{

    return 0;
}