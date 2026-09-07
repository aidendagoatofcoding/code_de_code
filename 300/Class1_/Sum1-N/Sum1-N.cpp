/*
sum from one to n
input: n
output: sum
  */
#include <bits/stdc++.h>
using namespace std;



int main() {
  long long n;
  cin >> n;
  long long sum;
  if (n % 2 == 0) {
    sum = (n / 2) * (n + 1);
  } else {
    sum = n * ((n + 1) / 2);
  }
  cout << sum << endl;

}
