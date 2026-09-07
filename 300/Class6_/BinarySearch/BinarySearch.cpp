/*12.  Binary Search
Problem ID: 1037Required Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 262144kB
Description
Binary Search: Enter n sorted numbers in ascending order, use binary search to determine whether the given number m exists.
 If it exists, output the first occurrence position from left to right (starting from 1). If there is no such number, output 0.

Input
The first line is an integer n, the second line has n integers ai representing the ordered sequence to be searched, and the third line 
has several integers mi representing the numbers to be searched (up to S).

Output
For each mioutput the position where it first appears, separated by spaces. If it doesn't exist, output 0.

Examples
Input 1
7
1 2 4 4 5 7 9
4 5 2 10
Output 1
3 5 2 0

*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> ans;
    int x;
    while (cin >> x) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (a[mid] < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (l < n && a[l] == x) {
            ans.push_back(l + 1);
        } else {
            ans.push_back(0);
        }
    }

    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}

