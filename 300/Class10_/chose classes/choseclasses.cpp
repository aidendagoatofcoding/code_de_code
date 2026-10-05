/*11.  Choose classes
Problem ID: 9858Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 524288kB
Description
School has n classes. Class i has the start time S_i and the end time E_i. At any given time, student can only attend one class, and can get the benefit only after attended the whole class. There are conflicts between the class schedules, and parents want their kids to learn as much as they can. How to choose the classes so that the students can attend most number of the classes?

Input
First line: an integer 
n
n 
(
n
≤
1000
)
(n≤1000), the number of classes available to choose from.
Followed by 
n
n lines: 2 integers per line, 
S
i
S 
i
​
  and 
E
i
E 
i
​
 . 
(
0
≤
S
i
<
E
i
≤
32767
)
(0≤S 
i
​
 <E 
i
​
 ≤32767)

Output
The max number of classes that a student can possibly attend.

Examples
Input 1
3
0 6
0 4
4 8
Output 1
2*/


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> classes(n);
    for(int i = 0; i < n; i++){
        cin >> classes[i].first >> classes[i].second;
    }
    sort(classes.begin(), classes.end(), [](auto &a, auto &b){ return a.second < b.second; });
    int count = 0; 
    int lastEndTime = -1;
    for(int i = 1; i <= n; i++){
        if(classes[i].first >= lastEndTime){
            count++;
            lastEndTime = classes[i].second;
        }
    }
    cout << count;

}