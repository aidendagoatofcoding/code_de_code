/*8.  Painting the Barn
Problem ID: 15380
Time Limit: 2000ms
Memory Limit: 262144kB

Farmer John is not good at multitasking. He gets distracted often, making it hard to complete long projects. Currently, he is trying to paint one side of his barn, but 
he keeps painting small rectangular areas and then getting sidetracked by the needs of tending to his cows, leaving some parts of the barn painted with more coats of paint than others.
We can describe the side of the barn as a 2D  plane, on which Farmer John paints N rectangles, each with sides parallel to the coordinate axes,
 each described by the coordinates of its lower-left and upper-right corner points.
Farmer John wants to apply several coats of paint to the barn so it doesn't need to be repainted again
 in the immediate future. However, he doesn't want to waste time applying an excessive number of coats of paint. It turns out that 
K coats of paint is the optimal amount. Please help him determine how much area of the barn is covered with exactly K coats of paint after he paints all his rectangles.

input format :
The first line contains two integers N and K.
The next N lines contain four integers x1, y1, x2, y2 describing the coordinates of the lower-left and upper-right corner points of each rectangle.

OUTPUT FORMAT :
Please output the area of the barn that is covered by exactly 
K
K coats of paint.

SAMPLE INPUT:

3 2
1 1 5 5
4 4 7 6
3 3 8 7
SAMPLE OUTPUT:

8

Problem credits: Nick Wu
*/
#include <bits/stdc++.h>
using namespace std;



int main() {
    long long n, k;
    
    cin >> n >> k;
    vector<vector<long long>> input(n, vector<long long>(4));
    for (long long i = 0; i < n; i++) {
        cin >> input[i][0] >> input[i][1] >> input[i][2] >> input[i][3];
    }
    //prefix sum approach
    
    long long arrsize = 1002;
    vector<vector<long long>> p_sum(arrsize, vector<long long>(arrsize, 0));
    
    for (long long i = 0; i < n; i++) {
        long long x1 = input[i][0];
        long long y1 = input[i][1];
        long long x2 = input[i][2];
        long long y2 = input[i][3];
        (p_sum[x1][y1])++;
        (p_sum[x2][y2])++;
        (p_sum[x2][y1])--;
        (p_sum[x1][y2])--;
    }
    //first row
    for (long long i = 2; i <arrsize; i++) {
        p_sum[i][1] += p_sum[i-1][1];
    }
    //first column
    for (long long j = 2; j < arrsize; j++) {
        p_sum[1][j] += p_sum[1][j-1];
    }

    for (long long i = 2; i < arrsize; i++) { //outer is for the rows
        for (long long j = 2; j < arrsize; j++) { //inner is for the columns
            p_sum[i][j] += p_sum[i-1][j] + p_sum[i][j-1] - p_sum[i-1][j-1];
        }
    }

    long long result = 0;
    for (long long i = 1; i < arrsize; i++) {
        for (long long j = 1; j < arrsize; j++) {
            if (p_sum[i][j] == k) {
                result++;
            }
        }
    }
    cout << result << endl;
    return 0;
}
