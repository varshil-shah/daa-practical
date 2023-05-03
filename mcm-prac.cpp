#include <iostream>
#include <string>
#include <iomanip>

#define MAX_SIZE 5
using namespace std;

int M[MAX_SIZE + 1][MAX_SIZE + 1] = {};
int K[MAX_SIZE + 1][MAX_SIZE + 1] = {};
int P[MAX_SIZE] = {};

void generateRandomNumber(int l, int h) {
  srand(time(NULL));
  for(int i = 0; i < MAX_SIZE; i++) {
    int random = rand() % (h - l + 1) + l;
    P[i] = random;
  }
}

void printMatrix(int M[MAX_SIZE + 1][MAX_SIZE + 1]) {
  for(int i = 0; i < MAX_SIZE; i++) {
    for(int j = 0; j < MAX_SIZE; j++) {
      cout << setw(5) << M[i][j];
    }
    cout << endl;
  }
}

string parenthesize(int S[][MAX_SIZE + 1], int i, int j) {
  if (i == j) {
    return "M" + to_string(i);
  }
  return "(" + parenthesize(S, i, S[i][j]) + "*" + parenthesize(S, S[i][j] + 1, j) + ")";
}

void mcm() {
  int j, q, min;
  for(int d = 1; d < MAX_SIZE - 1; d++) {
    for(int i = 1; i < MAX_SIZE - d; i++) {
      j = i + d;
      min = INT_MAX;
      for(int k = i; k <= j - 1; k++) {
        q = M[i][k] + M[k+1][j] + P[i-1] + P[k] + P[j];
        if(q < min) {
          min = q;
          K[i][j] = k;
        }
      }
      M[i][j] = min;
    }
  }
  cout << M[1][MAX_SIZE - 1] << " multiplications." << endl;
  printMatrix(M);
  cout << endl;
  printMatrix(K);
  cout << endl;
  cout << parenthesize(K, 1, MAX_SIZE - 1) << endl;
}

int main() {
  generateRandomNumber(16, 32);
  mcm();
  return 0;
}

