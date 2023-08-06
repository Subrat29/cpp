#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <list>
using namespace std;

void topSort(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
            topSort(neighbour, visited, s, adj);
    }

    s.push(node);
}

void printGraph(unordered_map<int, list<int>> &adj)
{
    for (auto it = adj.begin(); it != adj.end(); ++it)
    {
        cout << it->first << " -> ";
        for (int neighbor : it->second)
        {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Create adj list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v); // directed graph
    }

    // call dfs topological sort until function for all components
    vector<bool> visited(v);
    stack<int> s;
    vector<int> ans;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            topSort(i, visited, s, adj);
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    int v = 5; // Number of vertices
    int e = 4; // Number of edges

    vector<vector<int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 3},
    };

    vector<int> result = topologicalSort(edges, v, e);

    cout << "Topological Sort Order: ";
    for (int vertex : result)
    {
        cout << vertex << " ";
    }
    cout << endl;

    cout << "Graph:" << endl;
    unordered_map<int, list<int>> adj;
    for (const vector<int> &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
    }
    printGraph(adj);

    return 0;
}
