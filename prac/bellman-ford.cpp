#include <iostream>
#include <vector>
using namespace std;

class Edge {
  public:
    int from;
    int to;
    int weight;
};

void bellmanFord(vector<Edge>& edges, int src, int n) {
  vector<int> dist(n + 1, INT_MAX);
  dist.at(src) = 0;

  for(int i = 1; i < n; i++) {
    for(auto& e : edges) {
      if(dist[e.from] != INT_MAX && dist[e.from] + e.weight < dist[e.to]) {
        dist[e.to] = dist[e.from] + e.weight;
      }
    }
  }

  // Check if there is any -ve cycle
  for(auto& e : edges) {
    if (dist[e.from] != INT_MAX && dist[e.from] + e.weight < dist[e.to]) {
      cout << "Negative cycle found!" << endl;
      return;
    }
  }

  // Print shortest distances
  for (int i = 1; i <= n; i++) {
    cout << "Shortest distance from " << src << " to " << i << " is " << dist[i] << endl;
  }
}

int main() {
  int n, m, src;
  cout << "Enter no. of vertices: ";
  cin >> n;

  cout << "Enter no. of edges: ";
  cin >> m;

  vector<Edge> edges(n);
  cout << "Enter edges in the format 'from to weight':\n";
  for (int i = 0; i < m; i++) {
    cin >> edges[i].from >> edges[i].to >> edges[i].weight;
  }

  cout << "Enter source vertex: ";
  cin >> src;

  bellmanFord(edges, src, n);
  return 0;
}
