/*13.  The longest incremental subsequence
Problem ID: 3276Bonus Problem100pt(s)
Time Limit: 200ms
Memory Limit: 32768kB
Description
When a number sequence (series) 
b
i
b 
i
​
  has its elements 
b
1
<
b
2
<
.
.
.
<
b
n
b 
1
​
 <b 
2
​
 <...<b 
n
​
 , we call the sequence an incremental series.

For a given series (
a
1
a 
1
​
 , 
a
2
a 
2
​
 , ..., 
a
n
a 
n
​
 )，we can find some sub-sequence that are incremental series: (
a
i
1
a 
i1
​
 , 
a
i
2
a 
i2
​
 , ..., 
a
i
K
a 
iK
​
 )，where 1 <= i1 < i2 < ... < iK <= N。

For an instance,  series (1, 7, 3, 5, 9, 4, 8) has some incremental sub-sequences, such as (1, 7), (3, 4, 8), etc. The longest length of these sub-sequence is 4 (which corresonds to sub-sequence (1, 3, 5, 8)).

Now you are asked to find the longest incremental subsequence of a given sequence.

Input
The first line has only one integer number n, denoting the length of the series (sequence).

The 2nd line has n integer number for the number sequence.

Output
Output an integer representing the length of the longest Incremental subsequence

Examples
Input 1
7
1 7 3 5 9 4 8
Output 1
4
Constraint
1 <= n <= 1000, 1<= each element <=10000*/

#include <bits/stdc++.h> 
using namespace std; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, 1); // dp[i] will hold the length 

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }
    cout << result << endl;
     
    return 0;
}

