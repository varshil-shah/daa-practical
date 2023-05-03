#include <iostream>
using namespace std;

void printMatrix(int matrix[2][2], int n ) {

  for(int i = 0; i < n ;i++) {
    cout<<"\n";
    for(int j = 0; j < n; j++)
        cout<<matrix[i][j]<<"\t";
  }
}

int main() {
  int a[2][2], b[2][2], c[2][2], i, j;
  int m1, m2 , m3, m4, m5, m6, m7;

  cout<<"\n Enter the elements of first matrix : ";
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
        cout<<"\nEnter element : ";
        cin>>a[i][j];
    }
  }

  cout<<"\n Enter the elements of second matrix : ";
  for(int i = 0; i < 2; i++) {
    for(int j = 0; j < 2; j++) {
        cout<<"\nEnter element : ";
        cin>>b[i][j];
    }
  }
  cout<<"\nThe first matrix is as follows : \n";
  printMatrix(a,2);
  cout<<"\nThe second matrix is as follows : \n";
  printMatrix(b,2);

  m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]) ;
  m2 = b[0][0]*(a[1][0] + a[1][1]);
  m3 = a[0][0]*(b[0][1]- b[1][1]);
  m4 = a[1][1]*(b[1][0]-b[0][0]);
  m5 = b[1][1]*(a[0][0] + a[0][1]);
  m6 = (a[1][0]-a[0][0]) * (b[0][0] + b[0][1]);
  m7 = (b[1][0] + b[1][1]) *(a[0][1]- a[1][1]) ;

  c[0][0] = m1+m4-m5+m7;
  c[0][1] = m3+m5;
  c[1][0] = m2+ m4;
  c[1][1] = m1-m2+m3+m6;
  cout<<"\n final matrix : \n";

  printMatrix(c,2);


}
