/*3.  Why Did the Cow Cross the Road II
Problem ID: 15285Required Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
The long road through Farmer John's farm has 
N crosswalks across it, conveniently numbered 
1…N (1≤N≤100,000). To allow cows to cross at these crosswalks, FJ installs electric crossing signals, which light up with 
a green cow icon when it is ok for the cow to cross, and red otherwise. Unfortunately, a large electrical storm has damaged
 some of his signals. Given a list of the damaged signals, please compute the 
minimum number of signals that FJ needs to repair in order for there to exist some contiguous block of at least 
K working signals.

INPUT FORMAT (file maxcross.in):
The first line of input contains 
N, K and B. The next 
B lines each describe the ID number of a broken signal.

OUTPUT FORMAT (file maxcross.out):
Please compute the minimum number of signals that need to be repaired in order for there to be a contiguous block of 

K working signals somewhere along the road.

SAMPLE INPUT:

10 6 5
2
10
1
5
9
SAMPLE OUTPUT:

1

Problem credits: Brian Dean*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K, B;
    cin >> N >> K >> B;

    vector<long long> broken(B);
    for (long long i = 0; i < B; i++) {
        cin >> broken[i];
    }

    sort(broken.begin(), broken.end());
    long long min_repairs = B; // Initialize to the maximum possible repairs
    //use sliding window 
    long long left = 0;
    for (long long right = 0; right < B; right++) {
        // Move the left pointer to maintain a window of size K
        while (broken[right] - broken[left] >= K) {
            left++;
        }
        // Calculate the number of broken signals in the current window
        long long current_repairs = right - left + 1;
        min_repairs = min(min_repairs, current_repairs);
    }
    cout << min_repairs << "\n";
    return 0;
}
