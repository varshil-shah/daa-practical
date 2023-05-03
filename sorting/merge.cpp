#include <iostream>
#define ARRAY_SIZE 10
using namespace std;

void Merge(int A[], int l, int mid, int h) {
  int i, j, k;
  int B[ARRAY_SIZE] = {};
  i = l, j = mid + 1; k = l;
  
  while (i <= mid && j <= h) {
    if(A[i] < A[j])
      B[k++] = A[i++];
    else
      B[k++] = A[j++];
  }

  for(; i <= mid; i++)
    B[k++] = A[i];

  for(; j <= h; j++)
    B[k++] = A[j];

  for(i = l; i <= h; i++)
    A[i] = B[i];
}

void MergeSort(int A[], int n) {
  int p, l, h, mid, i;
  for(p = 2; p <= n; p = p * 2) {
    for(i = 0; i+p-1 < n; i = i + p) {
      l = i;
      h = i+p-1;
      mid = (l + h) / 2;
      Merge(A, l, mid, h);
    }
  }

  if(p/2 < n) {
    Merge(A, 0, p/2 - 1, n-1);
  }
}

void RMergeSort(int A[], int l, int h) {
  if(l < h) {
    int mid = (l + h) / 2;
    RMergeSort(A, l, mid);
    RMergeSort(A, mid + 1, h);
    Merge(A, l, mid, h);
  }
}

int main() {
  int A[] = {20, 50, 60, 10, 30, 90, 70, 80, 100, 40};
  int n = sizeof(A) / sizeof(int);
  RMergeSort(A, 0, n - 1);

  for(int i = 0; i < n; i++)
    cout << A[i] << '\t';
  return 0;
}
