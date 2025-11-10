// Write a program to determine the minimum spanning tree of a graph using Kruskal’s algorithm.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

class DisjointSet
{
public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

vector<Edge> kruskalMST(vector<Edge> &edges, int V)
{
    sort(edges.begin(), edges.end(), compareEdges);
    DisjointSet ds(V);
    vector<Edge> mst;

    for (Edge e : edges)
    {
        if (ds.find(e.src) != ds.find(e.dest))
        {
            ds.unionSets(e.src, e.dest);
            mst.push_back(e);
        }
    }
    return mst;
}

int main()
{
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}};

    vector<Edge> mst = kruskalMST(edges, V);

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (Edge e : mst)
    {
        cout << e.src << " -- " << e.dest << " == " << e.weight << endl;
    }

    return 0;
}