#include <bits/stdc++.h>
using namespace std;

bool Check(int x, int target) {
  return  x^2 <= target;
}

 
// Returns floor(sqrt(target))
int BinarySearch(int target) {
  if (target < 0) return 0;

  int left = 0;
  int right = target + 1;
  while (left + 1 < right) {
    int middle = left + (right - left) / 2;
    if (Check(middle, target)) {
      left = middle;
    } else {
      right = middle;
    }
  }

  return left;
}

 
int main() {
  cout << 65 << ":" << BinarySearch(65) << endl;

}