/*14.  Triangle of Numbers
Problem ID: 3657Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 524288kB
Description
Given a number triangle, find a path somewhere from the top to the bottom such that the sum of the numbers on the path is the largest.
Every step can only go straight down or down and to the right (diagonal);
The number of rows is less than or equal to 100;
The numbers in the triangle rows range from 0 to 99;

Input
The first line is an integer N to indicate the height of the tower (i.e., the number of rows in the triangle of numbers).
Then it is followed by N lines, with the i-th line having i integers.

Output
One integer number representing the largest sum through the path.

Examples
Input 1
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Output 1
30
Examples Explanation
In this example, the path should be 7->3->8->7->5 and the sum is 30.

Below is the path underlined in the given triangle:

       _7_
       / \
     _3_  8
     / \ / \
   _8_  1   0
   / \ / \ / \
  2  _7_  4   4
 / \ / \ / \ / \
4  _5_  2   6   5
*/


#include <bits/stdc++.h>
using namespace std;

int main(){
	//fastio
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int>> triangle(n);
	for (int i = 0; i < n; i++) {
		triangle[i].resize(i + 1);
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}
	// Dynamic programming to find the maximum path sum
	for (int i = n - 2; i >= 0; --i) {
		for (int j = 0; j <= i; ++j) {
			triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	cout << triangle[0][0] << endl;
}