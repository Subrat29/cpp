#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

//tc O(e logv)  e = edge, v = vertices
//sc O(v+e)

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // step1: create adj list
    unordered_map<int, list<pair<int, int>>> adj; // list of pairs

    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // step2: create distance vector and initialize with infinite values
    vector<int> dis(vertices);
    for (int i = 0; i < vertices; i++)
    {
        dis[i] = INT_MAX;
    }

    // step3: create a set on the basis (distance, node)
    set<pair<int, int>> st;

    // step4: initialise distance and set with src node
    dis[source] = 0;
    st.insert(make_pair(0, source));

    // step5: bfs type main logic
    while (!st.empty())
    {
        // fetch top record
        auto top = *(st.begin());

        int topDistance = top.first;
        int topNode = top.second;

        // remove top record
        st.erase(st.begin());

        // traverse on neighbours
        for (auto neighbour : adj[topNode])
        {
            if (topDistance + neighbour.second < dis[neighbour.first])
            {
                auto record = st.find(make_pair(dis[neighbour.first], neighbour.first));

                // if record found then erase it
                if (record != st.end())
                {
                    st.erase(record);
                }

                // distance update
                dis[neighbour.first] = topDistance + neighbour.second;

                // record push in set
                st.insert(make_pair(dis[neighbour.first], neighbour.first));
            }
        }
    }
    return dis;
}

int main()
{

    return 0;
}