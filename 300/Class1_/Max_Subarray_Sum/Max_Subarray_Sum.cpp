/*
14.  Maximum Subarray Sum
Problem ID: 14098Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.

Input
The first input line has an integer n: the size of the array.
The second line has n integers x1,x2,…,xn: the array values.
Output
Print one integer: the maximum subarray sum.

Constraints

Example

Input:
8
-1 3 -2 5 3 -5 2 2
Output:
9
*/
#include <bits/stdc++.h>
using namespace std;



int main() {
  long n;
  cin >> n;
  vector<long> arr(n);
  for (long i = 0; i < n; i++){
    cin >> arr[i];
  }
  long current = arr[0];
  long maximum = arr[0];
  for ( long i = 1; i<n; i++){ 
    current = max( current + arr[i] , arr[i] );
    maximum = max(current, maximum );
  
  
  }
  cout << maximum;
  
  
}
