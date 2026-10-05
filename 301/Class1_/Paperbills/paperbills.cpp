/*12.  General Paper Bill Problem
Problem ID: 20703Required Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 262144kB
Description
You have unlimited supply of paper bills: $1, $5, $7.

What's the min number of paper bills to pay 
N
N dollars?

Input
An integer 
N
N.

Output
An integer representing the min number of paper bills to pay 
N
N dollars.

Examples
Input 1
6
Output 1
2
Constraint

1≤N≤1000*/

#include <bits/stdc++.h>
using namespace std; 
int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    //MinBills(i) = 1 + min( MinBills(i-1), MinBills(i-5), MinBills(i-7) )
    for (int i = 1; i<=n; i++){
        dp[i] = 1 + dp[i - 1];
        if (i >= 5) {
            dp[i] = min(dp[i], 1 + dp[i-5]);
        }
        if (i >= 7) {
            dp[i] = min(dp[i], 1 + dp[i-7]);
        }
    
    }
    cout << dp[n] << endl;
}   