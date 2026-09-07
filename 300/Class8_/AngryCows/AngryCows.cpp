#include <bits/stdc++.h>
using namespace std;

bool Check(const vector<int> &positions,
           int minimum_distance,
           int required_cows) {
    if (required_cows == 1) return true;

    int placed = 1;
    int last_position = positions[0];

    for (int i = 1; i < (int)positions.size(); i++) {
        if (positions[i] - last_position >= minimum_distance) {
            placed++;
            last_position = positions[i];

            if (placed >= required_cows) return true;
        }
    }

    return false;
}

int BinarySearch(const vector<int> &positions,
                 int left,
                 int right,
                 int required_cows) {
    int answer = 0;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (Check(positions, middle, required_cows)) {
            answer = middle;
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return answer;
}

int main() {
    int total_cowshed_count, total_cow_count;
    cin >> total_cowshed_count >> total_cow_count;

    vector<int> cow_sheds(total_cowshed_count);
    for (int i = 0; i < total_cowshed_count; i++) {
        cin >> cow_sheds[i];
    }

    sort(cow_sheds.begin(), cow_sheds.end());

    int max_length = cow_sheds.back() - cow_sheds.front();
    int max_distance = BinarySearch(cow_sheds, 0, max_length, total_cow_count);

    cout << max_distance << endl;
    return 0;
}