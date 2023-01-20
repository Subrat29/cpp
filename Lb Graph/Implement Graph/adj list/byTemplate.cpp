#include <bits/stdc++.h>
using namespace std;
template <typename T>

class graph
{
public:
    unordered_map<T, list<T>> adj;

    void addEdge(T u, T v, bool direction)
    {
        // create edge u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }

    void print()                             // O/p sequence prob
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

    graph<int> g;

    for (int i = 0; i < edge; i++)
    {
        cout << "Enter edges: ";
        cin >> u >> v;
        g.addEdge(u, v, 0); // creating an undirected graph
    }
    cout << endl;

    // printing graph
    g.print();

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