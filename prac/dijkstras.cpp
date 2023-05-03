#include <iostream>
#include <vector>
using namespace std;

#define V 6

int selectMinVertex(vector<int>& value, vector<bool>& processed) {
  int min = INT_MAX;
  int vertex;
  for(int i = 0; i < V; i++) {
    if(!processed[i] && value[i] < min) {
      vertex = i;
      min = value[i];
    }
  }
  return vertex;
}
