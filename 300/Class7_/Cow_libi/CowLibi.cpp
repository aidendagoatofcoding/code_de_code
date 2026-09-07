/*
15.  Cow-libi
Problem ID: 15573Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description

**Note: The time limit for this problem is 4s, two times the default.**

Somebody has been grazing in Farmer John's 
(
1
≤
G
≤
1
0
5
)
(1≤G≤10 
5
 ) private gardens! Using his expert forensic knowledge, FJ has been able to determine the precise time each garden was grazed. He has also determined that there was a single cow that was responsible for every grazing incident.

In response to these crimes each of FJ's 
N
N 
(
1
≤
N
≤
1
0
5
)
(1≤N≤10 
5
 ) cows have provided an alibi that proves the cow was in a specific location at a specific time. Help FJ test whether each of these alibis demonstrates the cow's innocence.

A cow can be determined to be innocent if it is impossible for her to have travelled between all of the grazings and her alibi. Cows travel at a rate of 1 unit distance per unit time.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line of input will contain 
G
G and 
N
N separated by a space.

The next 
G
G lines contain the integers 
x
x, 
y
y, and 
t
t 
(
−
1
0
9
≤
x
,
y
≤
1
0
9
;
0
≤
t
≤
1
0
9
)
(−10 
9
 ≤x,y≤10 
9
 ;0≤t≤10 
9
 ) separated by a space describing the location and time of the grazing. It will always be possible for a single cow to travel between all grazings.

The next N lines contain 
ints separated by a space describing the location and time of each cow's alibi.

OUTPUT FORMAT (print output to the terminal / stdout):
Output a single integer: the number of cows with alibis that prove their innocence.

SAMPLE INPUT:

2 4
0 0 100
50 0 200
0 50 50
1000 1000 0
50 0 200
10 0 170
SAMPLE OUTPUT:

2
There were two grazings; the first at 
(
0
,
0
)
(0,0) at time 
100
100 and the second at 
(
50
,
0
)
(50,0) at time 
200
200.

The first cow's alibi does not prove her innocence. She has just enough time to arrive at the first grazing.

The second cow's alibi does prove her innocence. She is nowhere near any of the grazings.

Unfortunately for the third cow, being at the scene of the crime does not prove innocence.

Finally, the fourth cow is innocent because it's impossible to make it from her alibi to the final grazing in time.

Inputs 5-11: No additional constraints.

Problem credits: Mark Gordon
*/




#include <bits/stdc++.h>
using namespace std;

bool findDist(const array<long long, 3>& first,
              const array<long long, 3>& second) {
    long long deltaX = first[0] - second[0];
    long long deltaY = first[1] - second[1];
    long long deltaT = first[2] - second[2];
    long long distanceSquared = (deltaX * deltaX + deltaY * deltaY);
    long long timeSquared = (deltaT * deltaT);

    return distanceSquared <= timeSquared;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int G, N;
    cin >> G >> N;

    vector<array<long long, 3>> grazings(G);

    for (int i = 0; i < G; i++) {
        cin >> grazings[i][0] >> grazings[i][1] >> grazings[i][2];
    }

    vector<array<long long, 3>> alibis(N);

    for (int i = 0; i < N; i++) {
        cin >> alibis[i][0] >> alibis[i][1] >> alibis[i][2];
    }

    sort(grazings.begin(), grazings.end(), [](const auto& first, const auto& second) {
        return first[2] < second[2];
    });

    int innocent = 0;
    for (auto& alibi : alibis) {
        auto next = lower_bound(grazings.begin(), grazings.end(), alibi[2],
            [](const auto& grazing, long long time) {
                return grazing[2] < time;
            });

        // has next and has prev   
        if (next != grazings.end() && next !=grazings.begin()) {
            bool canReachNext = findDist(alibi, *next);
            bool canReachPrev = findDist(alibi, *prev(next));
            if( !canReachNext || !canReachPrev) {
                innocent++;
            }
         } else if( next != grazings.end()) {
            // has next, no previous
            bool canReachNext = findDist(alibi, *next);
            if(!canReachNext) {
                innocent++;
            }
        } else if(next !=grazings.begin()) {
            // has previous, no next
            bool canReachPrev = findDist(alibi, *prev(next));
            if( !canReachPrev) {
                innocent++;
            }
        }    
    } // for each alibi

    cout << innocent << '\n';
}