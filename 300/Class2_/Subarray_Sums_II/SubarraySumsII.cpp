/*
Subarray Sums II 
Problem ID: 14112
Time Limit: 2000ms
Memory Limit: 262144kB

Given an array of n integers, your task is to count the number of subarrays having sum x
Input
first line has two integers n and x: the number of elements and the target sum.
the next n lines have n integers: the elements of the array.
Output
Print one integer: the number of subarrays having sum x.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int main(){
  long n, x;
  cin >> n >> x;
  //use unordered_map to store prefix sums
  vector<long> arr(n);
  for (long i = 0; i < n; i++){
    cin >> arr[i];
  } 
  //prefix sum the full array
  unordered_map<long, long> prefixsums;
  prefixsums[0] = 1;
  long count = 0;
  long current_sum = 0;
  for (long i = 0; i < n; i++){
    current_sum += arr[i];
    if (prefixsums.find(current_sum - x) != prefixsums.end()){
      count += prefixsums[current_sum - x];
    } 
    //if the current sum hasnt been seen before then it would default to 0 then increase to 1
    prefixsums[current_sum]++;
  }
  cout << count;
}
