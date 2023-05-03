#include <iostream>
#include <vector>
using namespace std;

#define V 6

int selectMinVertex(vector<int>& value, vector<bool>& processed) {
  int min = INT_MAX;
  int vertex;
  for(int i = 0; i < V; i++) {
    if(!processed.at(i) && value.at(i) < min) {
      vertex = i;
      min = value.at(i);
    }
  }
  return vertex;
}

void dijkstra(int G[V][V]) {
  int parent[V] = {}; // Stores shortest path structure
  vector<int> value(V, INT_MAX);  // keep shortest path value for each vertex from src
  vector<bool> processed(V, false); // if true, means already processed

  // Assuming start point is node 0
  parent[0] = -1;  // Starting node has no parent
  value[0] = 0;  //  To get picked first

  // Loop over (V-1) vertexs
  for(int i = 0; i < V - 1; i++) {
    // Select the min value vertex
    int u = selectMinVertex(value, processed);

    // Mark that node as processed
    processed[u] = true;

    // Relax all the adjacent vertexs
    for(int j = 0; j < V; j++) {
      /**
      CONDITION TO RELAX THE EDGES -
      1. Edge must be present from U to j.
      2. Vertex j should not be included in shortest path graph
      3. Edge must is smaller then current edge weight
      */
      if(G[u][j] != 0 && !processed[j] && value[u] != INT_MAX && value[u] + G[u][j] < value[j]) {
        value[j] = value[u] + G[u][j];
        parent[j] = u;
      }
    }
  }

  for(int i = 0; i < V; i++) {
    cout << value.at(i) << '\t';
  }
}

int main() {
  int G[V][V] = {
    {0, 1, 4, 0, 0, 0},
    {1, 0, 4, 2, 7, 0},
    {4, 4, 0, 3, 5, 0},
    {0, 2, 3, 0, 4, 6},
    {0, 7, 5, 4, 0, 7},
    {0, 0, 0, 6, 7, 0}
  };

  dijkstra(G);
  return 0;
}
