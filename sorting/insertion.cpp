/**
Time Complexity -
Minimun - O(n) When the list is already sorted (ascending order)
Maximum - O(n^2) When the list is unsorted (descending order)

Swaps -
Minimum - O(1)
Maximum - O(n)

Space Complexity -
O(n)
*/

#include <iostream>
using namespace std;

void InsertionSort(int A[], int size) {
  for(int i = 1; i < size; i++) {
    int j = i - 1;
    int x = A[i];

    // Loop till current element is greater than x
    while (A[j] > x) {
      A[j + 1] = A[j];
      j--;
    }

    // Assign the x value to empty space position
    A[j + 1] = x;
  }
  cout << "Insertion sort completed!" << endl;
}

int main () {
  int A[] = {10, 50, 30, 20, 60, 70, 100, 80, 90};
  int size = sizeof(A) / sizeof(int);
  InsertionSort(A, size);

  for(int i = 0; i < size; i++) {
    cout << A[i] << '\t';
  }
  return 0;
}
