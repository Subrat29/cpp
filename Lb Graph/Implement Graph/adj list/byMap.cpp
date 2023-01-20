#include <bits/stdc++.h>
using namespace std;

class graph
{
public:

    // unordered_map<int, list<int>> adj;  it gives nonsequencial output
    map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) // dir = 0, Undirected graph && dir = 1, directed graph
    {
        // create edge u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print() // Output to shi aara h but sequence wise nii aara???
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";

            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int node = 5;
    int edge = 6;
    int u, v;

    graph g;

    for (int i = 0; i < edge; i++)
    {
        cout << "Enter edges: ";
        cin >> u >> v;
        g.addEdge(u, v, 0); // creating an undirected graph
    }

    cout << endl;
    g.print(); // printing graph

    return 0;
}

/*
0 1
1 2
2 3
3 1
3 4
0 4
*/