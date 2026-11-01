/*13.  Edit Distance 2
Problem ID: 15746Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 262144kB
Description
Time limit: 1.00 s
Memory limit: 256 MB
Edit a source string into a target string. And different operations have different costs.

The allowed operations and costs are:

Add one character to the string, cost x;
Remove one character from the string, cost y;
Replace one character in the string, cost z;
Your task is to calculate the minimum edit cost between two strings.

Input

The first input line contains 
a
,
b
,
c
a,b,c; 
(
1
≤
a
,
b
,
c
≤
9
)
(1≤a,b,c≤9)
The second input line has a string that contains 
n
n characters between A–Z.
The third input line has a string that contains 
m
m characters between A–Z.

Output

Print one integer: the minimum edit cost between the strings.

Constraints

1
≤
n
,
m
≤
5000
1≤n,m≤5000
Example

Input:

1 2 3

LOVE

MOVIE

Output:

4*/


#include <bits/stdc++.h>
using namespace std;


int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string src, dst;
  cin >> src;
  cin >> dst;
  src = " " + src;
  dst = " " + dst;

  int dp[5001][5001];
  // Initial subproblem solutions
  for (int j = 0; j < dst.size(); j++){
    dp[0][j] = j * a;
  }
    
  for (int i = 0; i < src.size(); i++){
    dp[i][0] = i * b;
  }

  for (int i = 1; i < src.size(); i++) {
    for (int j = 1; j < dst.size(); j++) {
      if (src[i] == dst[j]) {
        dp[i][j] = dp[i-1][j-1]; // Keep Current
      } else {
        dp[i][j] = min({dp [i-1][j  ] + b,      // remove from source, next: source less one, target stay the same 
                        dp [i  ][j-1] + a,      // add to source, next: source stay the same, target less one.
                        dp [i-1][j-1] + c       // replace, next: source less one, target less one.
                       });
      }
    }
  }

  cout << dp[src.size() - 1][dst.size() - 1] << endl;
}