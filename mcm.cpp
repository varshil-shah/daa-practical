#include <iostream>
using namespace std;

int main() {
  int n = 5;
  int p[] = {5, 4, 6, 2, 7};
  int m[5][5] = {0};
  int s[5][5] = {0};
  int j, min, q;

  for(int d = 1; d < n - 1; d++) {
    for(int i = 1; i < n - d; i++) {
      j = i + d;
      min = INT_MAX;
      for(int k = i; k <= j - 1; k++) {
        q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
        if(q < min) {
          min = q;
          s[i][j] = k;
        }
        m[i][j] = min;
      }
    }
  }
  cout << m[1][n-1] << " multiplications." << endl;
  return 0;
}
