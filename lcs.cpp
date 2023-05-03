#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int LCS(string T, string S,string& lcs) {
  int m = T.length();
  int n = S.length();
  int dp[MAX][MAX] = {};

  for(int i = 1; i <= m; i++) {
    for(int j = 1; j <= n; j++) {
      if(T[i-1] == S[j-1]) {
        // Character match, add 1 to LCS
        dp[i][j] = dp[i-1][j-1] + 1;
      }else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }

  int length = dp[m][n];
    lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (T[i-1] == S[j-1]) {
            // character is part of lcs, add to result string
            lcs = T[i-1] + lcs;
            i--;
            j--;
        } else if (dp[i-1][j] >= dp[i][j-1]) {
            // character not part of lcs, move to next row
            i--;
        } else {
            // character not part of lcs, move to next column
            j--;
        }
    }
    return length;
}

int main() {
  string text1 = "AGGTAB";
  string text2 = "GXTXAYB";
  string lcsS;
  int lcs = LCS(text1, text2, lcsS);
  cout << "Longest common subsequence: " << lcs << endl;
  cout << lcsS << endl;
  return 0;
}
