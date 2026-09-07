/*
Restaurant Customers
Problem ID: 14076
Time Limit: 2000ms
Memory Limit: 262144kB

you are given the starting and leaving times of customers in a resturant
find the maximum number of customers that are present in the resturant at the same time
INPUT:
FIRST LINE: A N Amount of  of customers
Next N LINES: two integers, the arrival and leaving times of the Nth customer
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<pair<int, int>> events;

  for (int i = 0; i < n; i++) {
    int arrive, leave;
    cin >> arrive >> leave;
    events.push_back({arrive, 1});    // arrival event
    events.push_back({leave, -1});    // departure event
  }

  sort (events.begin(), events.end());

  int current = 0;
  int best = 0;

  for(int i = 0; i < events.size(); i++) {
    current += events[i].second;
    best = max(best, current);
  }


  cout << best << endl;
  return 0;
}
