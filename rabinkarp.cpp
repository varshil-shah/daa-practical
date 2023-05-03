#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool check(string T, string P, int shift) {
  for(int i = 0; i < P.length(); i++) {
    if(T[i + shift] != P[i]) return false;
  }
  return true;
}

void rabinKarp(string T, string P, int q) {
  int p = 0;
  int t = 0;
  int n = T.length();
  int m = P.length();

  int h = (int)pow(10, m - 1) % q;

  // Calculate first hash
  for(int i = 0; i < m; i++) {
    t = (t * 10 + T[i]) % q;
    p = (p * 10 + P[i]) % q;
  }

  for(int s = 0; s <= n - m; s++) {
    if(t == p) {
      if(check(T, P, s)) {
        cout << "Substring found after shift " << s << endl;
      }else {
        cout << "Spurious hit" << endl;
      }
    }

    if(s < n - m) {
      // rolling hash
      t = ((t - (T[s] * h)) * 10 + T[s + m]) % q;
      if(t < 0) t += q;
    }
  }
}

int main() {
  string t = "aabacbadb";
  string p = "bad";

  rabinKarp(t, p, 13);
  
  return 0;
}
