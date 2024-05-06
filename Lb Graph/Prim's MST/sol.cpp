#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits>
#include <list>
#include <limits.h>
using namespace std;
 
//tc O(n^2)  --> it optimize by using priority queue and then tc O(nlogn) in line 46 - 54 we find minimum, we replace it by using pq

//it shows this <u, v, w>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // step1: create adj list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // step2: create key, mst, parent vector and initialize also || n+1 bc index ko hi node se darsha rha hu
    vector<int> key(n + 1);
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
        parent[i] = -1;
    }

    // step3: start the algo
    key[1] = 0;
    parent[1] = -1; //no need this

    for (int i = 1; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        for (int v = 1; v <= n; v++)
        {
            // find the min wali node
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }

        // mark min true
        mst[u] = true;

        // check its adjacent nodes
        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && key[v] > w)
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    //Now use parent array to find minimum spanning tree

    // create result
    // 0 se chla nhi skte bc in this ques sari node 1 se start horhi h and n pr end
    // 1 se chla nhi skte bc 1 ka parent to -1 h

    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}

int main()
{

    return 0;
}