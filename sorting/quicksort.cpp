#include <iostream>
using namespace std;

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int A[], int l, int h) {
  int pivot = A[l];
  int i = l, j = h;

  do {
    do { i++; }while (A[i] <= pivot);
    do { j--; } while(A[j] > pivot);

    if(i < j) swap(&A[j], &A[i]);
  } while(i < j);
  swap(&A[l], &A[j]);
  return j;
}

void QuickSort(int A[], int l, int h) {
  int j;
  
  // If there is atleast 2 elements in an array
  if(l < h) {
    j = partition(A, l, h);
    QuickSort(A, l, j);
    QuickSort(A, j+1, h);
  }
}

int main() {
  int A[] = {11, 13, 7, 12, 16, 9, 24, 10, 3, INT32_MAX};
  int size = sizeof(A) / sizeof(int);
  cout << size << endl;
  QuickSort(A, 0, size - 1);

  for(int i = 0; i < size - 1; i++)
    cout << A[i] << '\t';
  cout << endl;

  return 0;
}
