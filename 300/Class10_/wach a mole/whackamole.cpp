/*9.  Whac-A-Mole
Problem ID: 1317Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 65536kB
Description
Whac-A-Mole is a game that requires fast responses and quick decision making. At the beginning all the moles hide in the ground. Once the game starts they will all pop their heads up. It takes one second to hammer a mole, but each mole will reward you with a different point total. All the moles show up at the same time at the beginning, but each mole stays for a different limited amount of time and goes back underground after that (never to show up again). The goal is to find a strategy to optimize the hit sequence for the highest points reward.

Input:
3 lines in total. 

The first line contains an integer n (1<=n<=100) depicting that there are n moles popping out of the ground.

The second line of n space-separated integers describe the time of stay for each mole

The third line of n space-separated integers indicates the point/score (<=100) that for hitting the corresponding mole. The i-th number in each row represents the information of the i-th mole.

Output :

There is only one line and one integer, which represents the maximum game score that you could possibly get.

Sample Input:
5
5  3  6  1  4
7  9  2  1  5

Sample Output:
24
Data Range:
For 30% of the test cases, 1<=n<=10

For 60% of the test cases, 1<=n<=50

For 100% of the test cases, 1<=n<=100，value of the points <=100*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> stay(n), score(n);
    for (int i = 0; i < n; i++) {
        cin >> stay[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> score[i];
    }

    vector<pair<int, int>> moles(n);
    for (int i = 0; i < n; i++) {
        moles[i].first = stay[i];
        moles[i].second = score[i];
    }

    sort(moles.begin(), moles.end());

    priority_queue<int, vector<int>, greater<int> > minHeap;
    long long totalScore = 0;

    for (int i = 0; i < n; i++) {
        int s = moles[i].second;
        int t = moles[i].first;

        minHeap.push(s);
        totalScore += s;

        if ((int)minHeap.size() > t) {
            totalScore -= minHeap.top();
            minHeap.pop();
        }
    }

    cout << totalScore << '\n';
    return 0;
}