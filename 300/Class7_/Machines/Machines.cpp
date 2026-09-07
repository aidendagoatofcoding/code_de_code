/*
14.  Factory Machines
Problem ID: 14077Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
A factory has n machines which can be used to make products. 
Your goal is to make a total of t products.

For each machine, you know the number of seconds it needs to make a single product. 
The machines can work simultaneously, and you can freely decide how many products
 each machine produces.

What is the shortest time needed to make t products?

Input
The first input line has two integers n and t: the number of machines and products. 
The next line has n integers k1,k2,...,kn: the time needed to make a product using each machine.

Output
Print one integer: the minimum time needed to make t products.

Examples
Input 1 
3 7
3 2 5
Output 1
8
Examples Explanation
Explanation: Machine 1 makes two products, machine 2 makes four products 
and machine 3 makes one product.

Constraint
Constraints:
1≤n≤2×10^5
1≤t≤10^9
1≤ki≤10^9*/
#include <bits/stdc++.h>
using namespace std;

bool canMake(const vector<long long>& machines, long long time, long long target) {
	long long products = 0;
	for (long long machine : machines) {
		products += time / machine;
		if (products >= target) {
			return true;
		}
	}
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	long long t;
	cin >> n >> t;

	vector<long long> machines(n);
	long long fastest = LLONG_MAX;
	for (long long& machine : machines) {
		cin >> machine;
		fastest = min(fastest, machine);
	}
	
	long long low = fastest;
	long long high = fastest * t;
	long long answer = high;
	while (low <= high) {
		long long middle = low + (high - low) / 2;
		if (canMake(machines, middle, t)) {
			answer = middle;
			high = middle - 1;
		} else {
			low = middle + 1;
		}
	}
	cout << answer ;
}