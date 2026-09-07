
/*
9.  Rectangular Pasture
Problem ID: 15417
Bonus 
Problem100pt(s)

Description

Farmer John's largest pasture can be regarded as a large 2D grid of square "cells" (picture a huge chess board). Currently, there are 
N cows occupying some of these cells (1≤N≤2500).

Farmer John wants to build a fence that will enclose a rectangular region of cells; the rectangle must be oriented so its sides are parallel with the 
x and 
y axes, and it could be as small as a single cell. Please help him count the number of distinct subsets of cows that 
he can enclose in such a region. Note that the empty subset should be counted as one of these subsets.

INPUT FORMAT (input arrives from the terminal / stdin):
The first line contains a single integer 
N. Each of the next 
N lines Each of the next 
N lines contains two space-separated integers, indicating the 
(x,y) coordinates of a cow's cell. All 
x coordinates are distinct from each-other, and all 
y coordinates are distinct from each-other. All 
x and 
y values lie in the range 

OUTPUT FORMAT (print output to the terminal / stdout):
The number of subsets of cows that FJ can fence off. It can be shown that this quantity fits within a signed 64-bit integer (e.g., a "long long" in C/C++).

SAMPLE INPUT:

4
0 2
1 0
2 3
3 5
SAMPLE OUTPUT:

13

*/



//prefix sum approach
#include <bits/stdc++.h>
using namespace std;


void compress_coordinates(vector<pair<long long, long long>>& cows, long long N) {
        //coordinate compression
    sort(cows.begin(), cows.end());
    //set the x coordinates to the rankings
    for (long long i = 0; i < N; i++) {
        cows[i].first = i;
    }
    //swap x and y coordinates
    for (long long i = 0; i < N; i++) {
        swap(cows[i].first, cows[i].second);
    }
    sort(cows.begin(), cows.end());
    //set the y coordinates to the rankings
    for (long long i = 0; i < N; i++) {
        cows[i].first = i;
    }
    //swap x and y coordinates
    for (long long i = 0; i < N; i++) {
        swap(cows[i].first, cows[i].second);
    }

    // re-sort - why do we need this?
    sort(cows.begin(), cows.end());
}

int Get(vector<vector<long long>> &grid, int x, int y) {
    return grid[x][y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long N;
    cin >> N;
    vector<pair<long long, long long>> cows(N);
    for (long long i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }
    compress_coordinates(cows, N);
    
    //mark cows as 1 in the grid and prefix sum
    vector<vector<long long>> grid(N + 1, vector<long long>(N + 1, 0));
    for (long long i = 0; i < N; i++) {
        grid[cows[i].first][cows[i].second] = 1;
    }

    // Compute prefix sum
    for (long long i = 1; i < N; i++) {
        //1d prefix sum first row
        grid[0][i] += grid[0][i - 1];
    }
    for (long long i = 1; i < N; i++) {
        //1d prefix sum first column
        grid[i][0] += grid[i - 1][0];
    }
    
    for (long long i = 1; i < N; i++) {
        for (long long j = 1; j < N; j++) {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + grid[i][j];
        }
    }

    long long count = 0;
    //sellect 2 polong longs as the upper and lower boundaries of the rectangle  
    for (long long i = 0; i < N; i++) {
        for (long long j = i + 1; j < N; j++) {

            int cow1_x = cows[i].first;
            int cow1_y = cows[i].second;
            int cow2_x = cows[j].first;
            int cow2_y = cows[j].second;
            //casework: 
            
            //case 1: cow1 is lower left, cow2 is upper right
            if (cow1_y < cow2_y) {
                /*   Left              Right
                     XX ...............cow2 XXX
                     XX ..................  XXX
                     XX cow1 .............  XXX

                    topRight= bottomRight +topLeft -bottomLeft +R_cnt */
                int R_topRight    = Get(grid, N-1, cow2_y);
                int R_bottomRight = Get(grid, N-1, cow1_y);
                int R_bottomLeft  = Get(grid, cow2_x, cow1_y);
                int R_topLeft     = Get(grid, cow2_x, cow2_y);
                int R_cnt = R_topRight -R_bottomRight -R_topLeft +R_bottomLeft ;

                int L_topRight =    Get(grid, cow1_x, cow2_y);
                int L_bottomRight = Get(grid, cow1_x, cow1_y); 
                int L_cnt = L_topRight -L_bottomRight;
                count += (R_cnt +1)* (L_cnt+1); //right adds cow2, left adds cow1
            }
            //case 2: cow1 is upper left, cow2 is lower right
            else if (cow1_y > cow2_y) {
                /*    Left                Right
                      XX cow1...............   XXX
                      XX ...................   XXX    
                      XX .................cow2 XXX       */                 
                int R_topRight    = Get(grid, N-1, cow1_y);
                int R_bottomRight = Get(grid, N-1, cow2_y);
                int R_bottomLeft  = Get(grid, cow2_x, cow2_y);
                int R_topLeft     = Get(grid, cow2_x, cow1_y);
                int R_cnt = R_topRight -R_bottomRight -R_topLeft +R_bottomLeft ;

                int L_topRight   = Get(grid, cow1_x, cow1_y);
                int L_bottomRight = Get(grid, cow1_x, cow2_y); 
                int L_cnt = L_topRight -L_bottomRight ;
                count += (R_cnt+1) * (L_cnt);  // right adds cow2, left already includes cow1
            }
        }
    }
    count += N+1;
    cout << count << endl;
    return 0;
}

