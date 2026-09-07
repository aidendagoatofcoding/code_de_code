/*7.  Cow Dance Show
Problem ID: 15297Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
After several months of rehearsal, the cows are just about ready to put on their annual dance performance; this year they are performing the famous bovine ballet "Cowpelia".

The only aspect of the show that remains to be determined is the size of the stage. A stage of size 
K
K can support 
K
K cows dancing simultaneously. The 
N
N cows in the herd (
1
≤
N
≤
10
,
000
1≤N≤10,000) are conveniently numbered 
1
…
N
1…N in the order in which they must appear in the dance. Each cow 
i
i plans to dance for a specific duration of time 
d
(
i
)
d(i). Initially, cows 
1
…
K
1…K appear on stage and start dancing. When the first of these cows completes her part, she leaves the stage and cow 
K
+
1
K+1 immediately starts dancing, and so on, so there are always 
K
K cows dancing (until the end of the show, when we start to run out of cows). The show ends when the last cow completes her dancing part, at time 
T
T.

Clearly, the larger the value of 
K
K, the smaller the value of 
T
T. Since the show cannot last too long, you are given as input an upper bound 
T
m
a
x
T 
max
​
  specifying the largest possible value of 
T
T. Subject to this constraint, please determine the smallest possible value of 
K
K.

INPUT FORMAT (file cowdance.in):
The first line of input contains 
N
N and 
T
m
a
x
T 
max
​
 , where 
T
m
a
x
T 
max
​
  is an integer of value at most 1 million.

The next 
N
N lines give the durations 
d
(
1
)
…
d
(
N
)
d(1)…d(N) of the dancing parts for cows 
1
…
N
1…N. Each 
d
(
i
)
d(i) value is an integer in the range 
1
…
100
,
000
1…100,000.

It is guaranteed that if 
K
=
N
K=N, the show will finish in time.

OUTPUT FORMAT (file cowdance.out):
Print out the smallest possible value of 
K
K such that the dance performance will take no more than 
T
m
a
x
T 
max
​
  units of time.

SAMPLE INPUT:

5 8
4
7
8
6
4
SAMPLE OUTPUT:

4

Problem credits: Delphine and Brian Dean*/





#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> arr, int K, long long maxTime) {
    vector<long long> stage(K, 0);

    for (int i = 0; i < K; ++i) {
        stage[i] = arr[i];
    }

    for (int i = K; i < (int)arr.size(); ++i) {
        int minIndex = 0;
        for (int j = 1; j < K; ++j) {
            if (stage[j] < stage[minIndex]) {
                minIndex = j;
            }
        }

        stage[minIndex] +=arr[i];
    }

    long long finishTime = 0;
    for (int i = 0; i < K; ++i) {
        finishTime = max(finishTime, stage[i]);
    }

    return finishTime <= maxTime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long max;
    cin >> N >> max;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int low = 1, high = N;
    while (low < high) {
        int mid = (low + high) / 2;
        if (check(arr, mid, max)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';
    return 0;
}