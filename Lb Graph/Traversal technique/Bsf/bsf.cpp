#include <bits/stdc++.h>
using namespace std;

void preparedAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> edges)
{
    // Traverse all edges
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // store frontNode into ans
        ans.push_back(frontNode);

        // traverse all neighbours of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) // ye edges di h pair me to kyu adjlist nikal rhe h ??  given like: 1-2, 2-3, 0-1, pair me isliye h
{
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    preparedAdjList(adjList, edges);

    // traverse all components of a graph (use loop bc including disconnecting graph varna direct bfs call hoti maam)
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i])
        {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main()
{

    return 0;
}