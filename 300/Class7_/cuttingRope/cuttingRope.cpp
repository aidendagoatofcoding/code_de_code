/*13.  Rope Cutting
Problem ID: 3579Bonus Problem100pt(s)
Time Limit: 200ms
Memory Limit: 131072kB
Description
There are N ropes, each with a length of 
Li, and you need to cut out 
K ropes of the same length from them. What is the possible longest length for each of these 
K ropes? Please round your answer to the nearest hundredth. For example, for 
1.357785, please output 1.35.


Input
In the first line, there are two integers, N and K

In the second line, there are 
N floating-point numbers 
Output
Output a floating-point number, keeping exactly 2 decimal places.

Examples
Input 1
4 11
8.02 7.43 4.57 5.39
Output 1
2.00
*/

#include <bits/stdc++.h>
using namespace std;

bool canCut(const vector<long long>& ropes, long long length, long k) {
	long pieces = 0;
	for (long long rope : ropes) {
		pieces += rope / length;
		if (pieces >= k) {
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long n;
	long k;
	cin >> n >> k;

	vector<long long> ropes(n);
	long long upperBound = 0;
	for (long long& rope : ropes) {
		double length;
		cin >> length;
		rope = (long long )(length *1000.0);
		upperBound = max(upperBound, rope);
	}

	long long low = 0;
	long long high = upperBound;
	long long answer = 0;
	while (low <= high) {
		long long middle = low + (high -low) / 2;
		if (canCut(ropes, middle, k)) {
			answer = middle;
			low = middle+1 ; //+1;
		} else {
			high = middle-1;
		}
	}
	
    // wrong:
	//cout << fixed << setprecision(2) << answer /10000 << endl;
	//cout << setw(2) << setfill('0') <<123;
	long long answer1 = answer/10;
	long long intPart = answer1/100;
    long long fractPart = answer1 % 100;
	cout << intPart << "." << setw(2)<< setfill('0') << fractPart <<endl;

	/*double doubleAnswer = answer/1000;
	
	doubleAnswer*=100;
	long long temp = doubleAnswer;
	double doubleTemp = temp;
	doubleTemp /= 100;
	cout <<  doubleTemp; */

} 

