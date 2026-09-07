/*6.  Divide array into segments
Problem ID: 9253Bonus Problem100pt(s)
Time Limit: 1000ms
Memory Limit: 512000kB
Description
Given an array 
A which consists of 
N integers, you have to divide it into 
M segments, where the segments are continuous and the segment with the maximum sum is the minimized.

For example, if we divide the array 
{4,2,4,5,1} into 
3 segments:

Dividing it into 
{4,2},{4,5},{1}, the sums of three segments are 
6,9,1, where the maximum sum is 9

If we divide it into 
{4},{2,4},{5,1}, the sums of three segments are 
4,6,6, where the maximum sum is 6;

However you divide this array, the maximum sum will be no less than 6.

Input：
The first line contains two positive integers N, M；
The second line contains N non-negative integers A i​ (separated by space).

Output：
An integer representing the minimized maximum sum of the segments.

Sample input：
5 3
4 2 4 5 1
Sample output：

6

*/




#include <bits/stdc++.h> 
using namespace std;

bool check(vector<int>& A, int N, int M, long long maxSum) {
    int segments = 1;
    long long currentSum = 0;
    
    for(int i = 0; i < N; i++) {
        if(currentSum + A[i] <= maxSum) {
            currentSum += A[i];
        } else {
            segments++;
            currentSum = A[i];
            if(segments > M) {
                return false;
            }
        }
    }
    
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    long long maxElement = 0;
    long long totalSum = 0;
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
        maxElement = max(maxElement, (long long)A[i]);
        totalSum += A[i];
    }
    
    long long left = maxElement;
    long long right = totalSum;
    long long answer = totalSum;
    
    while(left < right) {
        long long mid = (left + right) / 2;
        if(check(A, N, M, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}