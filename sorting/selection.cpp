/**

*/

#include <iostream>
using namespace std;

void SelectionSort(int A[], int size) {
  int i, j, k;
  for(i = 0; i < size - 1; i++) {
    for(j = k = i; j < size; j++) {
      if(A[j] < A[k]) {
        k = j;
      }
    }

    // Swap
    int temp = A[i];
    A[i] = A[k];
    A[k] = temp;
  }
  cout << "Selection sort completed!" << endl;
}

int main() {
  int A[] = {10, 50, 30, 20, 60, 70, 100, 80, 90};
  int size = sizeof(A) / sizeof(int);
  SelectionSort(A, 2);

  for (int i = 0; i < size; i++) {
    cout << A[i] << '\t';
  }
  return 0;
}
