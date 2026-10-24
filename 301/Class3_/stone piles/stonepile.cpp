/*7.  Combine the stone piles
Problem ID: 7186Required Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 131072kB
Description
Time limit：1s   Memory limit：128M
 

Description：
There are N piles of stones in a line. The i-th pile of stones weighs Ai
. Now you have to combine the stones into one pile. You can only combine two adjacent piles. The weight of the new pile and the energy it costs equal to the sum of two piles' weight.
 Find out the minimum energy it costs to combine all N piles into one.

 
Input：
The 1st line: a positive integer N（N<=300）--- the number of piles of stones
The 2nd line: N positive integers---the weight of each pile of stones (<=1000)。

 

Output：
a positive integer--- the minimum energy it costs to combine all N piles into one.

 

Sample input：

4
1 3 5 2
Sample output：
22
 

note：
First combine 1 & 2, and then combine 3 & 4.*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    // len is j- 1 + 1 
     for (int len =  1; len <= n; len++ ) {
        for (int i = 0; i + len <n; ++i) {
            int j = i + len ;
            if ( j < n){
                long long intervalSum = prefix[j + 1] - prefix[i];

                dp[i][j] = LLONG_MAX;
                for (int k = i; k < j; k++ ) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + intervalSum);
                }
            }
        }
    } 


    cout << dp[0][n - 1] << endl;
    return 0;
}