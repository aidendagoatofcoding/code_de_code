// 301 students: solve all ??

#include <bits/stdc++.h>

using namespace std;

 

int main() {
  string src, dst;
  cin >> src >> dst;
  // The content of a and b starts at index 1
  cin >> src;
  cin >> dst;
  src = " " + src;
  dst = " " + dst;

  int dp[5001][5001];
  // Initial subproblem solutions
  for (int j = 0; j < dst.size(); j++) dp[0][j] = j;
  for (int i = 0; i < src.size(); i++) dp[i][0] = i;

 

  for (int i = 1; i < src.size(); i++) {
    for (int j = 1; j < dst.size(); j++) {
      if (src[i] == dst[j]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min({dp[i - 1][j] + 1,  
                        dp[i][j - 1] + 1,    
                        dp[i - 1][j - 1] + 1 
                       });
      }

    }

  }

 

  cout << dp[src.size() - 1][dst.size() - 1] << endl;

}