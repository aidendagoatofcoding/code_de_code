/*14.  Apartments
Problem ID: 14016Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment. Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.

Input
The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference. The next line contains n integers a1, a2, ..., an: the desired apartment size of each applicant. If the desired size of an applicant is x, he or she will accept any apartment whose size is between x-k and x+k. The last line contains m integers b1, b2, ..., bm: the size of each apartment.

Output
Print one integer: the number of applicants who will get an apartment.

Examples
Input 1
4 3 5
60 45 80 60
30 60 75
Output 1
2
Examples Explanation
For the first test sample, applicants 1 and 3 can get an apartment, so the output is 2.

Constraint
1 ≤ n, m ≤ 2 * 10^5, 0 ≤ k ≤ 10^9, 1 ≤ ai, bi ≤ 10^9*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n), apartments(m);
    for (int i = 0; i<n ; i++ ){
        cin >> applicants[i];
    }
    for (int i = 0; i<m ; i++ ){
        cin >> apartments[i];
    }
    sort (applicants.begin(), applicants.end());
    sort (apartments.begin(), apartments.end());
    int answer = 0; 
    for (int i = 0, j = 0; i < n && j < m; ) {
        if (apartments[j] >= applicants[i] - k && apartments[j] <= applicants[i] + k) {
            answer++;
            i++;
            j++;
        } else if (apartments[j] < applicants[i] - k) {
            j++;
        } else {
            i++;
        }
    }
    cout << answer << "\n";
}
/*
do this problem by using two pointers technique. put the pointer for applicants and apartments at the beginning of the sorted arrays.
while both pointers are within the bounds of their respective arrays, compare the current applicant's desired size with the current apartment's size. 
If the apartment size is within the acceptable range for the applicant (i.e., between desired size - k and desired size + k),
 increment the answer and move both pointers forward. If the apartment size is too small, move the apartment pointer forward. 
 If the apartment size is too large, move the applicant pointer forward. Continue this process until one of the pointers reaches the end of its array. 
 Finally, print the answer which represents the number of applicants who will get an apartment.
*/