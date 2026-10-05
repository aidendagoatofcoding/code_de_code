/*1.  Swapping permutations
Problem ID: 3578Required Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 131072kB
Description
You have a permutation of numbers from 1 to N, denoted as 
P
1
,
P
2
,
P
3
,
.
.
.
,
P
N
P 
1
​
 ,P 
2
​
 ,P 
3
​
 ,...,P 
N
​
 . Additionally, you have M swappers 
(
x
1
,
y
1
)
,
(
x
2
,
y
2
)
,
.
.
.
,
(
x
M
,
y
M
)
(x 
1
​
 ,y 
1
​
 ),(x 
2
​
 ,y 
2
​
 ),...,(x 
M
​
 ,y 
M
​
 ), which swap the position of 
x
i
x 
i
​
  with 
y
i
y 
i
​
 . You can use each swapper any number of times, and your goal is to maximize the number of positions where 
P
i
=
i
P 
i
​
 =i. Output the maximum number of such positions possible.

Input format:

The first line has two integers, N and M

The next M lines will have a pair, 
x
i
,
y
i
x 
i
​
 ,y 
i
​
 , denoting a swapper

Output :

An integer representing the maximum number of positions where 
P
i
=
i
P 
i
​
 =i

Sample input 1:

5 2

5 3 1 4 2

1 3

5 4

Sample output 1:

2

Sample input 2:

10 8

5 3 6 8 7 10 9 1 2 4

3 1

4 1

5 9

2 5

6 5

3 5

8 9

7 9

Sample output 2:

8



*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n + 1);
        sz.resize(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            if (sz[rootA] < sz[rootB]) {
                swap(rootA, rootB);
            }
            parent[rootB] = rootA;
            sz[rootA] += sz[rootB];
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> p(N + 1);
    for (int i = 1; i <= N; i++) cin >> p[i];

    DSU dsu(N);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        dsu.unite(x, y);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (dsu.find(i) == dsu.find(p[i])) {
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
