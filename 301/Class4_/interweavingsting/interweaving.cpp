/*3.  Interleaving String
Problem ID: 15628Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 524288kB
Description
Time limit: 1s   Memory limit: 512M

 

Description :

Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m 

substrings

 respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.

tXR9OXqeLK2iAHQhBEmXhXtcPIzm7wcme3DA9XG9T0lKFdA2fxSdQSZoM60QmCIAiDoDJegiAIwiDIgRAEQRAGQQ6EIAiCMAhyIARBEIRBkAMhCIIgDIIcCEEQBGEQ5EAIgiAIgyAHQhAEQRgEORCCIAjCIMiBEARBEAZBDoQgCIIwCHIgBEEQhEGQAyEIgiAM4v+lKqCfxkVjDgAAAABJRU5ErkJggg==

 

Input :

Three lines, each containing a string.

s1, s2, s3. (0 ≤ s1.length, s2.length ≤ 100,  0 ≤ s3.length ≤ 200)

Output :

"yes" or "no".

 

Sample input 1:

abc
xby
axbbyc
Sample output 1:

yes
 

Sample input 2:

abc
xby
abbxyc
Sample output 2:

no
 

 */
#include <bits/stdc++.h> 
using namespace std;

void check(string s1, string s2, string s3) {
    int n = s1.size();
    int m = s2.size();
    if (s3.size() != n + m) {
        cout << "no" << endl;
        return;
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    
    if (dp[n][m]) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}

int main() { 
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int n = s1.size();
    int m = s2.size();
    check(s1, s2, s3);
}


