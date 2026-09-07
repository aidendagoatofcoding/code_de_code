/*13.  Sum of Three Values
Problem ID: 14096Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
Time limit: 2s; Memory limit: 256M

Description 

You are given an array of 
n integers, and your task is to find three values at distinct positions(start with 1) whose sum is x.

Input

The first input line has two integers 
n and x: the array size and the target sum
The second line has n integers 


Output
Print three integers: the positions of the values. If there are several solutions, 
you may print any of them. If there are no solutions, print IMPOSSIBLE

Sample Input:
4 8
2 7 5 1

Sample Output:
4 1 3

*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; i++) {
        int left = i + 1;
        int right = n - 1;
        while (left < right) {
            int sum = arr[i].first + arr[left].first + arr[right].first;
            if (sum == x) {
                cout << arr[i].second;
                cout << " " << arr[left].second;
                cout << " " << arr[right].second << endl;
                return 0;
            } else if (sum < x) {
                left++;
            } else {
                right--;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}