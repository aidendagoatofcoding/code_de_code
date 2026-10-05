/*2.  Angry Cows
Problem ID: 15249Required Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
Bessie the cow has designed what she thinks will be the next big hit video game: "Angry Cows". The premise, which she believes is completely original, is that the player shoots cows with a slingshot into a one-dimensional scene consisting of a set of hay bales located at various points on a number line. Each cow lands with sufficient force to detonate the hay bales in close proximity to her landing site. The goal is to use a set of cows to detonate all the hay bales.

There are 
N
N hay bales located at distinct integer positions 
x
1
,
x
2
,
…
,
x
N
x 
1
​
 ,x 
2
​
 ,…,x 
N
​
  on the number line. If a cow is launched with power 
R
R landing at position 
x
x, this will causes a blast of "radius 
R
R", destroying all hay bales within the range 
x
−
R
…
x
+
R
x−R…x+R.

A total of 
K
K cows are available to shoot, each with the same power 
R
R. Please determine the minimum integer value of 
R
R such that it is possible to use the 
K
K cows to detonate every single hay bale in the scene.

INPUT FORMAT (file angry.in):
The first line of input contains 
N
N (
1
≤
N
≤
50
,
000
1≤N≤50,000) and 
K
K (
1
≤
K
≤
10
1≤K≤10). The remaining 
N
N lines all contain integers 
x
1
…
x
N
x 
1
​
 …x 
N
​
  (each in the range 
0
…
1
,
000
,
000
,
000
0…1,000,000,000).

OUTPUT FORMAT (file angry.out):
Please output the minimum power 
R
R with which each cow must be launched in order to detonate all the hay bales.

SAMPLE INPUT:

7 2
20
25
18
8
10
3
1
SAMPLE OUTPUT:

5
Problem credits: Brian Dean*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, K;
    cin >> N >> K;

    //use a binary search to find the minimum R
    vector<int> haybales(N);
    cin >> haybales[0];
    for (int i = 1; i < N; i++) {
        cin >> haybales[i];
    }
    sort(haybales.begin(), haybales.end());

    int left = 0, right = 1e9;
    while (left < right) {
        int mid = left + (right - left) / 2;
        int cowsUsed = 0;
        int i = 0;
        while (i < N) {
            cowsUsed++;
            int loc = haybales[i] + 2 * mid; // the farthest haybale this cow can detonate
            while (i < N && haybales[i] <= loc) {
                i++;
            }
        }
        if (cowsUsed <= K) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << '\n';

}