/*
7.  Forest Queries
Problem ID: 14107Required Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
You are given an n×n grid representing the map of a forest. Each square is either empty or contains a tree.
The upper-left square has coordinates (1,1), and the lower-right square has coordinates (n,n).
Your task is to process q queries in the form of: how many trees are inside a given rectangle in the forest?

Input
The first input line has two integers n and q: the size of the forest and the number of queries.
Then, there are n lines describing the forest. Each line has n characters: . is an empty square and * is a tree.
Finally, there are q lines describing the queries. Each line has four integers  
corresponding to the top left and bottom right corners of the rectangle.

Output
Print the number of trees inside each rectangle.

Examples
Input 1
4 3
.*..
*.**
**..
****
2 2 3 4
3 1 3 1
1 1 2 2
Output 1
3
1
2

*/
#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> forest(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                forest[i][j] = 1;
            } else {
                forest[i][j] = 0;
            }
        }
    }
    //prefix sum
    //brute force calculate prefix
    vector<vector<int>> prefix_sum(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            prefix_sum[i][j] = forest[i - 1][j - 1] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }
    for (int i = 0; i < q; i++) {
        //we will use the prefix sum to calculate the number of trees in each rectangle
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int count = prefix_sum[r2][c2] - prefix_sum[r1 - 1][c2] - prefix_sum[r2][c1 - 1] + prefix_sum[r1 - 1][c1 - 1];
        cout << count << "\n";
    }
    

}
