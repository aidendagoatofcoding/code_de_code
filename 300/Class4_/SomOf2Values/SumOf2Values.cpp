#include <bits/stdc++.h>

using namespace std;

 

int main(){
   const int N_MAX = 2e5+1;
   int n, sum;
   cin >> n >> sum;
   vector<pair<long long, int>> arr(n);

   for(int i = 0; i < n; i++) {
       int value;
       cin >> value;
       arr[i] = {value, i+1};
   }

   //sort!!
   sort(arr.begin(), arr.end());
   // 2 pointers

   bool found = false;

   int left = 0, right = n - 1;
   while(left < right) {
       long long current_sum = arr[left].first + arr[right].first;
       if(current_sum == sum) {
           cout << arr[left].second << " " << arr[right].second << endl;
           found = true;
           break;
       } else if(current_sum < sum) {
           left++;
       } else {
           right--;
       }

   }

   if(!found) cout << "IMPOSSIBLE" << endl;

}