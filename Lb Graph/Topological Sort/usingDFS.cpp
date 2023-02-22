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

    // catch
    s.push(node);
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
    // unordered_map<int, bool> visited;     //when i use map then tle maar rha h re...so use vector

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

    return 0;
}