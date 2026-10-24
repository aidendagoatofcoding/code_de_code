/*12.  The longest common subsequence
Problem ID: 3587Required Problem100pt(s)
Time Limit: 200ms
Memory Limit: 131072kB
Description
Find the longest common subsequence of the two strings given.

Input
two lines, each containing a string

Output
an integer representing the length of the longest common subsequence

Examples
Input 1
xjoixjoi
joyjoy
Output 1
4
Input 2
xsrrnzkbhzkhzmvkjevsrbdiclckmsgpgngyckzvgysvwcgwayjokqactfxtivfbdwprufivtgg
zhbpvlxfkisdneogdseenjlewrobjhpppjczyxeaiqanaztksnpfwyhdjvipgwzznmnnxwraiiei
Output 2
21
Constraint
string length should be less than or equal to 1000.*/
#include <bits/stdc++.h>
using namespace std;

int llcs(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}






int main() {
    string s1, s2;
    cin >> s1 >> s2;

    int n = s1.size();
    int m = s2.size();

    cout << llcs(s1, s2) << endl;

    return 0;
}