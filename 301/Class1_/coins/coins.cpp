/*13.  Minimizing Coins

 */

#include <bits/stdc++.h>
using namespace std; 
int main(){
    long n, x;
    cin >> n >> x;
    vector<long> c(n + 1);
    vector<long> dp(x + 1, LONG_MAX);
    dp[0] = 0;

    for (long i = 1; i <= n; i++) {
        cin >> c[i];
    }
    //sort (c.begin(), c.end());//unnecessary
    // initialize;
    /*for (long j = 1; j <= n; j++) {
        if( c[j]<= x) {
           dp[ c[j]]=1;
        }
    } */
    // why removing below still works? I think it is required, but was able to pass all xcamp test cases. Why?
    dp[0]=0;

    for (long i = 1; i <= x; i++) {
        for (long j = 1; j <= n; j++) {
            if (i >=c[j] && dp[i -c[j]] != LONG_MAX ) {
                dp[i] = min(dp[i], dp[i -c[j]] +1);
            }
        }
    }

    if (dp[x] == LONG_MAX) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }
}   