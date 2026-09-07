/*16.  Binary search 2
Problem ID: 9331Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 262144kB
Description
Binary search: Enter an ordered list of n numbers in ascending order, and use binary search to find the position
(starting from 1) of the first number greater than m.

Input
The first line is an integer n. The second line is n integers representing the ordered sequence to be searched. The third line is several integers mi representing the numbers to be searched.

Output
Output several integers separated by spaces, representing the positions of the first numbers that are greater than m i.

Examples
Input 1
7
1 2 2 4 5 7 9
2 3 4 10*/

#include <bits/stdc++.h>
using namespace std;

vector <int> arr;
int main(){
    int N;
    cin >> N;
    int value;
    for(int i = 0 ; i < N ; i++){
        cin >> value;
        arr.push_back(value);
    }

    while (cin >> value){
        auto upper = upper_bound(arr.begin() , arr.end() , value);
        cout << upper - (arr.begin() - 1) << " ";
    }
}

