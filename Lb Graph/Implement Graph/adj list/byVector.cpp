#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertex = 5;
    int edges = 6;

    // vector<int> g[vertex];           // Doubts: why take vertex+1 bc yha vertex 0 nhi lere na
    vector<int> g[vertex+1];            // rows define but columns not define bc col me pta nii kitne node aa jaye

// vector<int> V[] is an array of vectors.
// vector< vector<int> > V is a vector of vectors.

    cout << "Enter edges" << endl;

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cout << endl;
    

    for (int i = 0; i < vertex; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

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