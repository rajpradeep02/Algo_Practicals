// Write a program to implement the Bellman-Ford algorithm to find the shortest paths from a given source node to all other nodes in a graph.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
	int src, dest, weight;
};

void bellmanFord(int V, int E, vector<Edge>& edges, int src) {
	vector<int> dist(V, INT_MAX);
	dist[src] = 0;

	// Relax all edges V-1 times
	for (int i = 1; i < V; ++i) {
		for (int j = 0; j < E; ++j) {
			int u = edges[j].src;
			int v = edges[j].dest;
			int w = edges[j].weight;
			if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}

	// Check for negative-weight cyclesl
	for (int j = 0; j < E; ++j) {
		int u = edges[j].src;
		int v = edges[j].dest;
		int w = edges[j].weight;
		if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
			cout << "Graph contains negative weight cycle" << endl;
			return;
		}
	}

	cout << "Vertex\tDistance from Source" << endl;
	for (int i = 0; i < V; ++i)
		cout << i << "\t" << dist[i] << endl;
}

int main() {
	int V, E;
	cout << "Enter number of vertices and edges: ";
	cin >> V >> E;
	vector<Edge> edges(E);
	cout << "Enter each edge as: src dest weight" << endl;
	for (int i = 0; i < E; ++i) {
		cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
	}
	int src;
	cout << "Enter source vertex: ";
	cin >> src;
	bellmanFord(V, E, edges, src);
	return 0;
}

