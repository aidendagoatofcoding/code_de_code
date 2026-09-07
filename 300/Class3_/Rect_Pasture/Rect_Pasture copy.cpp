#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to hold coordinates
struct Point {
    int x, y;
};

// 2D Prefix Sum Grid (N <= 2500, so 2502 x 2502 is sufficient)
int P[2502][2502];

// Helper function to query number of cows in rectangle [x1, x2] x [y1, y2]
int query(int x1, int y1, int x2, int y2) {
    return P[x2][y2] - P[x1 - 1][y2] - P[x2][y1 - 1] + P[x1 - 1][y1 - 1];
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    vector<Point> pts(N);
    for (int i = 0; i < N; i++) {
        cin >> pts[i].x >> pts[i].y;
    }

    // --- STEP 1: Coordinate Compression ---
    // Compress X coordinates to range [1, N]
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });
    for (int i = 0; i < N; i++) {
        pts[i].x = i + 1;
    }

    // Compress Y coordinates to range [1, N]
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return a.y < b.y;
    });
    for (int i = 0; i < N; i++) {
        pts[i].y = i + 1;
    }
 
    // --- STEP 2: Build 2D Prefix Sum Array ---
    for (int i = 0; i < N; i++) {
        P[pts[i].x][pts[i].y] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            P[i][j] += P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1];
        }
    }

    // Sort points by compressed X coordinate for easy pair iteration
    sort(pts.begin(), pts.end(), [](const Point& a, const Point& b) {
        return a.x < b.x;
    });

    // --- STEPS 3, 4, 5: Count Subsets ---
    long long total_subsets = 1; // 1 accounts for the empty subset

    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            int x1 = pts[i].x;
            int x2 = pts[j].x;
            int y1 = min(pts[i].y, pts[j].y);
            int y2 = max(pts[i].y, pts[j].y);

            // A: Cows in X-range [x1, x2] with Y >= y2
            int A = query(x1, y2, x2, N);
           
            // B: Cows in X-range [x1, x2] with Y <= y1
            int B = query(x1, 1, x2, y1);

            // Multiply top choices (A) by bottom choices (B)
            total_subsets += 1LL * A * B;
        }
    }

    cout << total_subsets << "\n";

    return 0;
}