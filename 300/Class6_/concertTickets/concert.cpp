/*
15.  Concert Tickets
Problem ID: 14021
Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description
Time limit: 1.00 s
Memory limit: 512 MB
There are n concert tickets available, each with a certain price. Then, 
m customers arrive, one after another.

Each customer announces the maximum price they are willing to pay for a ticket, and after this, 
they will get a ticket with the nearest possible price such that it does not exceed the maximum price.

Input

The first input line contains integers 
n and 
m: the number of tickets and the number of customers.

The next line contains 
n integers : the price of each ticket.

The last line contains 
m integers : the maximum price for each customer in the order they arrive.


Output

Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
If a customer cannot get any ticket, print −1.


 
Example

Input:
5 3
5 3 7 8 5
4 8 3

Output:
3

8

-1
*/



#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    auto comparator = [](const long long& a, const long long& b) { return a > b; };

    multiset<long long, decltype(comparator)> tickets(comparator);
    for (int i = 0; i < n; i++) {
        long long price;
        cin >> price;
        tickets.insert(price);
    }


    //greedy algorithm, sort the tickets in ascending order
    //sort(tickets.begin(), tickets.end());
    
    for (int i = 0; i < m; i++) {
        long long maxPrice;
        cin >> maxPrice;
        //long long bestPrice;

        //2 pointer technique, find the largest ticket price that is less than or equal to the maxPrice
        multiset<long long, decltype(comparator)>::iterator bestPrice = tickets.lower_bound(maxPrice);
        if(bestPrice != tickets.end()) {
            cout << *bestPrice << "\n";
            tickets.erase(bestPrice);
        } else {
            cout << -1 << "\n";
        }
    }


}



        /*
        int left = 0, right = tickets.size()-1;
        int bestPrice = -1;
        
        while (left <= right) {
            int mid = (left + right) / 2;

            if (tickets[mid] == maxPrice) {
                bestPrice = tickets[mid];
                break;
            }

            if (tickets[mid] < maxPrice) {
                bestPrice = tickets[mid];
                left = mid + 1;
            }  else {
                right = mid - 1;
            }

        }
    */
