/*
12.  Cutting Wood
Problem ID: 8466Required Problem100pt(s)
Time Limit: 3000ms
Memory Limit: 624288kB
Description
Description:
Bob is summoned by Alice to chop down trees. He needs to get a total of m meters of wood, and Bob has a strange logging machine to collect this wood. 
The machine works like this: Bob determines a height limit of h (meters), and sets the machine's saw blade to the height of h. After the height of the saw blade is set, 
it cuts each tree at that height, causing the part higher than h to fall down. If a tree is lower than h then nothing will be cut down.
 What Bob collects is the part that has been cut off the tree.

For example, if the height of trees in a row are respectively 20, 15, 10 and 17 (meters), and Bob sets the saw blade to a height of 15, the remaining heights of the trees 
(stumps) after cutting will be 15, 15, 10 and 15 Meters, and Bob will get 5 meters from the first tree and 2 meters from the fourth tree, for a total of 7 meters of wood.

Bob cares about the environment, so he wants to minimize the amount of wood he cuts, which is why he wants to set the blade as high as possible while still 
being able to collect m meters of wood for Alice. Please help Bob find the maximum integer height h for the saw blade so that he can get at least m meters of wood,
 where lowering the blade height by one meter will produce less than the required m meters of woods.

Input:
The first line has two integers n and m, where n represents the number of trees, and m represents the total length of wood Bob needs to colloect.

The 2nd line has n integers which describe the height of each tree (height). The sum of all tree heights is guaranteed to be more than m.

Output:
One line with one integer, indicating the highest possible height of the saw blade.

Sample Input:

5 20
4 42 40 26 46



Sample Output:

36



*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;
	long m;
	cin >> n >> m;

	vector<long> trees(n);
	long tallest = 0;
	for (long& height : trees) {
		cin >> height;
		tallest = max(tallest, height);
	}

	long low = 0;
	long high = tallest;
	long answer = 0;

	while (low <= high) {
		long mid = low + (high - low) / 2;
		long collected = 0;

		for (int height : trees) {
			if (height > mid) {
				collected += height - mid;
			}
		}

		if (collected >= m) {
			answer = mid;
			low = mid + 1;
		} 
        
        else {
			high = mid - 1;
		}
	}

	cout << answer ;
	return 0;
}