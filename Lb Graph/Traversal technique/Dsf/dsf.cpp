#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

 // linear tc, sc
 // ye sasur adj list ki kya jarurat h seedhe graph ko traverse ku ni krte, visited map banakr.

void dfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &component)
{
    //step1: store node in compo
    component.push_back(node);

    //step2: mark visited
    visited[node] = true;

    //step3: recursive call for every connected node
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prepare adlist
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    // for all nodes call dfs, if not visited, and use for loop bc if disconnected component present
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            vector<int> component;                    //ye sasur compo ku le liya h... 4 disonnected graph has many compo
            dfs(i, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main()
{

    return 0;
}