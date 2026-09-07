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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n), apartments(m);
    for (int i = 0; i < n; ++i) {
        cin >> applicants[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> apartments[i];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int answer = 0;
    int j = 0; // index into apartments

    for (int i = 0; i < n; ++i) {
        while (j < m && apartments[j] < applicants[i] - k) ++j; // skip too small apartments
        if (j < m && apartments[j] <= applicants[i] + k) { // found a suitable apartment
            answer++;
            j++; // use this apartment
        }
    }

    cout << answer << '\n';
}
/*
the method is to sort both the applicants and apartments,
 then use a two-pointer technique to find suitable matches. 
 For each applicant, we move the apartment pointer forward until we find an apartment that is within the acceptable range. 
 If we find a match, we increment the answer and move to the next apartment. 
 This ensures that we maximize the number of applicants who get an apartment while maintaining efficiency with a time complexity of O(n log n + m log m) due to sorting.
*/