/*13.  Subarray Distinct Values
Problem ID: 14295Required Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB


Given an array of n integers, your task is to calculate 
the number of subarrays that have at most k distinct values

Input
The first input line has two integers n and k.

The next line has 
n integers : the contents of the array.

Output
Print one integer: the number of subarrays.

Example

Input:
5 2
1 2 3 1 1

Output:
10
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long ans = 0;
    unordered_map<int, int> freq;
    int left = 0;
    for (int right = 0; right < n; right++) {
        freq[a[right]]++;
        while (freq.size() > k) {
            freq[a[left]]--;

            if (freq[a[left]] == 0) {
                freq.erase(a[left]);
            }

            left++;
        }
        ans += right - left + 1;
    }



    cout << ans << "\n";
    return 0;
}