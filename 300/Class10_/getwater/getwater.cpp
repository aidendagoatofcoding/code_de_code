/*8.  Get water
Problem ID: 8100Required Problem100pt(s)
Time Limit: 100ms
Memory Limit: 131072kB
Description
There are n people lining up in front of a faucet for water. Suppose it takes Ti time for person i to get water. Please find out the particular sequence of the people in the line such that the average waiting time would be minimized.

Input
The first line contains n.
The second line contains n integers, T1，T2，…，Tn (separated by a space) where Ti means the time it takes for each person i to get water.

Output
The first line contains the sequence of those people in the line, in an arrangement from 1 to n. The second line is the average waiting time in this sequence (round to the hundredth).

Examples
Input 1
10
56 12 1 99 1000 234 33 55 99 812
Output 1
3 2 7 8 1 4 9 6 10 5
291.90
Examples Explanation
Explanation for sample 1:
The sequence in the line is 3 2 7 8 1 4 9 6 10 5, and the corresponding water fetching time for each person is 12 56 55 99 56 1000 99 234 812 33. The average waiting time is 291.90

Constraint
n<=1000
Ti<=1e6, the value of Ti may repeat.
In the case when Ti value is repeated, sorted them in the same order as input.*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> people(n);
    for (int i = 0; i < n; i++) {
        cin >> people[i].first;
        people[i].second = i + 1; // store original index
    }
    sort(people.begin(), people.end()); // sort by time, stable sort to maintain order for equal times
    //use greedy algo to minimize average waiting time
    double total_waiting_time = 0;
    double current_waiting_time = 0;
    for (int i = 0; i < n-1; i++) {
        current_waiting_time += people[i].first;
        total_waiting_time += current_waiting_time;
    }
    double average_waiting_time = total_waiting_time / n;
    for (int i = 0; i < n; i++) {
        cout << people[i].second << " ";
    }
    cout << endl;
    cout << fixed << setprecision(2) << average_waiting_time << endl;
    
}
