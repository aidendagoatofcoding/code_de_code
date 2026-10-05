/*14.  Road Construction
Problem ID: 14126Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 262144kB
Description
There are 
N cities and initially no roads between them. However, every day a new road will be constructed, 
and eventually there will be a total 
of M roads.
A cluster is a group of cities where there is a route between any two cities using the roads. After each day, 
your task is to find the number of clusters and the size of the largest cluster.

 

Input
The first input line has two integers n and 
m: the number of cities and roads. The cities are numbered 1, 2, 3... n.

Then, there are 
m lines describing the new roads. Each line has two integers a and b representing a new road being constructed between cities a and b.
You may assume that every road will be constructed between two different cities.

 

Output
Print m lines, each line containing two integers: 
the number of clusters and the size of the largest cluster after building the road.

Sample input:
5 3
1 2
1 3
4 5

Sample output:

4 2
3 3
2 3


Time limit: 1.00 s

Memory limit: 256 MB*/

#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent, size;
    int clusters, largest;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        clusters = n;
        if (n > 0) {
            largest = 1;
        } else {
            largest = 0;
        }
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
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
            // connect smaller tree to larger tree, confirm that root x is the smaller one           
            if (size[rootX] > size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
            largest = max(largest, size[rootX]);
            clusters--;
        }
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
        cout << dsu.clusters << " " << dsu.largest << "\n";
    }

}