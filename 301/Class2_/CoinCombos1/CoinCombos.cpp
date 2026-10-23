#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const long long MOD = 1000000007LL;

    long long n, x;
    cin >> n >> x;

    vector<long long> coins(n);
    for (long long i = 0; i < n; i++) {
        cin >> coins[i];
    }

    vector<long long> dp(x + 1, 0);
    dp[0] = 1;

    for (long long s = 1; s <= x; s++) {
        for (long long coin : coins) {
            if (s >= coin) {
                dp[s] = (dp[s] + dp[s - coin]) % MOD;
            }
        }
    }

    cout << dp[x] << '\n';
    return 0;
}