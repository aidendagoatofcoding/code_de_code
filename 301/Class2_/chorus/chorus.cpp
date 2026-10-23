/*14.  Chorus formation
Problem ID: 3663Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 135000kB
Description
Time Limit: 1s    Memory  Limit: 128M
 
Description:
N
N students stand in a row, and the music teacher asked the (N - K) students to leave, so that the remaining 
K
K students are arranged in a chorus formation.

The chorus formation refers to such a formation: 
K
K students are numbered 
1
,
2
,
.
.
.
,
K
1,2,...,K from left to right, and their heights are 
T
1
,
T
2
,
.
.
.
,
T
K
T 
1
​
 ,T 
2
​
 ,...,T 
K
​
 , and their height meets 
T
1
 
<
T
2
<
.
.
.
<
T
i
T 
1
​
  <T 
2
​
 <...<T 
i
​
 , 
T
i
>
T
i
+
1
>
.
.
.
>
T
K
T 
i
​
 >T 
i+1
​
 >...>T 
K
​
  (1 ≤ i ≤ K).

Given the height of all 
N
N students, please calculate the minimum students to leave to make the remaining students line up in a chorus formation.

 

Input :
The first line has an integer 
N
N (2 ≤ N ≤ 100), indicating the total number of students.

The second line has 
N
N integers separated by spaces. The i-th integer 
T
i
T 
i
​
  (130 ≤ Ti ≤ 230) is the height (cm) of the i-th student.

 

Output :
An integer, which means the minimum number of students needed to leave.

 

Sample Input:
8
186 186 150 200 160 130 197 220

Sample output:
4

Appointment:
For 50% of the data,  n ≤ 20;

For 100% of the data, n ≤ 100.*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // inc[i] = length of the longest increasing 
    vector<int> inc(n, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j] < a[i]) {
                inc[i] = max(inc[i], inc[j] + 1);
            }
        }
    }

    // dec[i] = length of the longest decreasing
    vector<int> dec(n, 1);
    for (int i = n - 2; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (a[j] < a[i]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int best = 0;
    for (int i = 0; i < n; ++i) {
        best = max(best, inc[i] + dec[i] - 1);
    }

    cout << n - best << '\n';
}