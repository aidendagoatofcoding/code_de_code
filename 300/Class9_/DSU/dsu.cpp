/*12.  Disjoint Set Union
Problem ID: 8214Required Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 524288kB
Description
This problem is simply the classic disjoint set union algorithm. There are N elements, and there will be M operations to be applied. Each element starts in its own set, i.e., there are N sets to start with. Each of these M operations will either merge two sets together or query if two elements are in the same set. See input format for more details.

 

Input：

The first line contains two integers N and M, which means there are N elements and M operations.

The next M lines, each line contains three integers Zi、Xi、Yi.

When Zi=1，merge the two sets which contain Xi and Yi.

When Zi=2，if Xi and Yi belong to the same set, output "Y". Otherwise output "N".

 

Output：

As described above, for each Zi=2, there is a line of output. Each line contains a capital letter, "Y" or "N".

 

Sample input 1：

4 7

2 1 2

1 1 2

2 1 2

1 3 4

2 1 4

1 2 3

2 1 4

Sample output 1：

N

Y

N

Y

 

Note：

N<=10000，M<=200000。*/

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;

        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY]; 
            
            
        }
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    DSU dsu(N);

    for (int i = 0; i < M; i++) {
        int Z, X, Y;
        cin >> Z >> X >> Y;
        if (Z == 1) {
            dsu.unite(X, Y);
        } 
        else if (Z == 2) {
            if (dsu.connected(X, Y)) {
                cout << "Y" << endl;
            } else {
                cout << "N" << endl;
            }
        }
    }


    return 0;
}