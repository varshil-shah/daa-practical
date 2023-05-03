#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void vertexCover(const vector<vector<int>>& G) {
  int n = G.size();
  vector<int> degrees(n);
  unordered_set<int> cover;

  // Compute degree of all vertices
  for(int i = 0; i < n; i++) {
    degrees[i] = G[i].size();
  }

  while(true) {
    // Find the vertex with max degree
    int max_degree = -1;
    int max_vertex = -1;

    for(int i = 0; i < n; i++) {
      if(degrees[i] > max_degree) {
        max_degree = degrees[i];
        max_vertex = i;
      }
    }

    if(max_degree == 0) {
      // No more vertives with +ve degree, done
      break;
    }

    // Add max degree vertex to its neighbour & cover
    cover.insert(max_vertex);
    for(auto neighbour : G[max_vertex]) {
      degrees[neighbour]--;
    }
    degrees[max_vertex] = 0;

  }

  // print the result
  cout << "Vertex cover: ";
  for (int vertex : cover) {
    cout << vertex << " ";
  }
  cout << endl;
}

int main() {
  // example graph
  vector<vector<int>> graph = {{1, 2}, {0, 2, 3}, {0, 1, 3, 4}, {1, 2, 4, 5}, {2, 3, 5}, {3, 4}};

  vertexCover(graph);

  return 0;
}
