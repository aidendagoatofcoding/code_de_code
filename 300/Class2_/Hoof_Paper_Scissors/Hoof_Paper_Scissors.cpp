/*
14.  Hoof, Paper, Scissors
Problem ID: 15298Bonus Problem100pt(s)
Time Limit: 2000ms
Memory Limit: 262144kB
Description

You have probably heard of the game "Rock, Paper, Scissors".
 The cows like to play a similar game they call "Hoof, Paper, Scissors".
The rules of "Hoof, Paper, Scissors" are simple. Two cows play against each-other. 
They both count to three and then each simultaneously makes a gesture 
that represents either a hoof, a piece of paper, or a pair of scissors. 
Hoof beats scissors (since a hoof can smash a pair of scissors), 
scissors beats paper (since scissors can cut paper), and paper beats hoof 
(since the hoof can get a papercut). For example, if the first cow makes a 
"hoof" gesture and the second a "paper" gesture, then the second cow wins. 
Of course, it is also possible to tie, if both cows make the same gesture.

Farmer John wants to play against his prize cow, Bessie, at 
N games of "Hoof, Paper, Scissors". Bessie, being an expert at the game, can predict each of FJ's gestures before he makes it. 
Unfortunately, Bessie, being a cow, is also very lazy. As a result, she tends to play the same gesture multiple times in a row. 
In fact, she is only willing to switch gestures at most once over the entire set of games. 
For example, she might play "hoof" for the first x games, then switch to "paper" for the remaining N−x games.

Given the sequence of gestures FJ will be playing, please determine the maximum number of games that Bessie can win.

INPUT FORMAT:
The first line of the input file contains N.

The remaining N lines contains FJ's gestures, each either H, P, or S.

OUTPUT FORMAT :
Print the maximum number of games Bessie can win, given that she can only change gestures at most once.

SAMPLE INPUT:
5
P
P
H
P
S
SAMPLE OUTPUT:
4
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    int wins = 0;
    cin >> N;
    vector<char> gestures(N);
    for (int i = 0; i < N; i++) {
        cin >> gestures[i];
    }
    //caluculate the prefix and store in 3 seperate arrays
    vector<int> prefix_h(N, 0);
    vector<int> prefix_p(N, 0);
    vector<int> prefix_s(N, 0);
    int cnt_p = 0;
    int cnt_s = 0;
    int cnt_h = 0;

    for (int i = 0; i < N; i++) {

        switch(gestures[i]) {
            case 'P': 
               cnt_p++; break;
            case 'S': 
               cnt_s++; break;
            case 'H': 
               cnt_h++; break;
        }
        prefix_p[i]= cnt_p;
        prefix_s[i]= cnt_s;
        prefix_h[i]= cnt_h;
    }

    int max_wins = 0;

    for (int i = 0; i < N; i++) { 
        int before = max( {prefix_h[i], prefix_p[i], prefix_s[i]} );
        int after = max( {prefix_h[N-1] - prefix_h[i], prefix_p[N-1] - prefix_p[i], prefix_s[N-1] - prefix_s[i]} );
        max_wins = max( {max_wins, before + after} );
    }
    cout << max_wins << endl;
}





