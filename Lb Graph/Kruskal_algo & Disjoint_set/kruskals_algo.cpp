#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// create comprator
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

// Step2: initialize parent & rank vector
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Step3: find parent
int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

// Step4: create union set
void UnionSet(vector<int> &parent, vector<int> &rank, int u, int v)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        parent[v] = u; // if both rank equal to kisi ko bhi parent bna do but inc its rank
        rank[u]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    // step0: sort edges
    sort(edges.begin(), edges.end(), cmp);

    // Step1: create parent and rank vector
    vector<int> parent(n);
    vector<int> rank(n);

    // initlize them
    makeSet(parent, rank, n);

    //iterate edges list one by one

    int minWt = 0; 

    for(int i=0; i<edges.size(); i++)
    {
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        if(u != v)
        {
            minWt += wt;
            UnionSet(parent, rank, u, v);
        }
    }
    return minWt;
}

int main()
{

    return 0;
}