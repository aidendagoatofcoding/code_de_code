/*14.  Maximum Subarray Sum II
Problem ID: 14099Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
Given an array of n integers, your task is to find the maximum sum of values in a contiguous subarray with a length between a and b.

Input
The first input line has three integers n, a and b: the size of the array and the minimum and maximum subarray length. The second line has n integers x1,x2,...,xn: the array values.

Output
Print one integer: the maximum subarray sum.

Examples
Input 1
8 1 2
-1 3 -2 5 3 -5 2 2
Output 1
8
Examples Explanation
For test sample 1, the maximum sum in a contiguous subarray of length 2 is 8.

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    if (!(cin >> n >> a >> b)) return 0;

    vector<ll> pref(n+1, 0);
    for (int i = 1; i <= n; ++i) {
        ll x; cin >> x;
        pref[i] = pref[i-1] + x;
    }

    multiset<ll> s; // holds possible prefix sums 
    ll answer = LLONG_MIN;

    for (int i = 1; i <= n; ++i) {
        if (i - a >= 0) {
            s.insert(pref[i-a]);
        }
        if (i - b - 1 >= 0) {
            // remove one occurrence from the multiset
            auto temp = s.find(pref[i-b-1]);
            if (temp != s.end()) {
                s.erase(temp);
            }
        }
        if (!s.empty()) {
            answer = max(answer, pref[i] - *s.begin());
        }
    }

    cout << answer << '\n';
    return 0;
}