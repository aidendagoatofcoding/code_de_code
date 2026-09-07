/*13.  Friendship Circle
Problem ID: 9561Bonus Problem100pt(s)
Time Limit: 100ms
Memory Limit: 131072kB
Description
There are n students in class. Some of them are friends, and some of them are not. Friendship has transitivity. For example, if A is B's friend, and B is C's friend, 
then A will be C's friend as a result of transitivity. A social circle is defined as a set of people who are all friends with each other. 
Note that there could be multiple social circles.

An n by n matrix M is given, representing the friendships in class. If M[i][j] = 1, the i-th student and j-th student are direct friends with each other; 
otherwise their relationship is unknown (with transitivity students could be friends even if they are not friends directly). Please compute the number of social circles in total.

Input:
The first line is an integer, n.

Over the next n lines, there are n integers in each line, either a 1 or 0, where a 1 represents a direct friendship.

Output:
One integer representing total number of social circles.

Sample Input:
3
1 1 0
1 1 1
0 1 1
Sample Output:
1
Constraints:
1≤n≤200*/



#include <bits/stdc++.h>
using namespace std;


struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 1);
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
            if (rank[rootX] < rank[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            rank[rootX] += rank[rootY]; 
        }
    }
};

int main() {
    int n;
    cin >> n;
    DSU dsu(n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int friendship;
            cin >> friendship;
            
            // only need to unite the friendship if i < j (j< i is same unite)
            if (friendship == 1 && i < j) {
                dsu.unite(i, j);
            }
        }
    }
    int circles = 0;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            circles++;
        }
    }
    cout << circles << endl;

    return 0;
}


