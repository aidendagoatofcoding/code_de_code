/*
13.  Mice and holes
Problem ID: 7310Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 524288kB
Description
Description of the topic
In a one dimensional world, there are n mice and m mouse holes. All mice can only go to the left, and only one mouse can enter one hole. It is ensured that the number of holes is greater than that of the mice, that the position of holes will not overlap, and that each mouse has at least one hole it can enter.  

Find the minimum total distance for all the mice to enter the hole.

Input format
The first line contains two integers n, m (n <= 300,000, n <= m <= 500,000)

The second line has n positive integers, and each positive integer represents the position of a mouse p (1 <= p <=10^9), The third line has m positive integers, and each positive integer represents the position q of a hole (1 <= q <= 10^9).

Output format
The minimum total distance for all the mice to enter the hole.

Sample input

3 5
6 7 10
1 2 5 8 9
Sample output

7
Time and memory limit

2s, 512M
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> mice(n), holes(m);
    for (int i = 0; i < n; ++i) cin >> mice[i];
    for (int i = 0; i < m; ++i) cin >> holes[i];

    sort(holes.begin(), holes.end(), greater<long long >());

    sort(mice.begin(), mice.end(), greater<long long>());
    long long answer = 0;
    int h = 0; // first unused hole index

    // For each mouse (largest first), pick the first hole that is <= mouse.
    // With descending order, upper_bound(..., greater<int>()) gives that hole.
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(holes.begin() + h, holes.end(), mice[i], greater<long long>());
        answer += 1LL * mice[i] - *it;
        h = (it - holes.begin()) + 1;
    }

    cout << answer << '\n';
    return 0;
}

