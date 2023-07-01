#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e4+5;

int t[MAXSZ], f[MAXSZ];

int main() {

    cin.sync_with_stdio(0); cin.tie(0);

    int n, k; 
    cin >> n >> k;

    for (int i=0; i<n; i++){
        for (int j =0 ; j<k; j++){
            char c; cin >> c;

            if (c == 'T') t[i] |= 1 << j;
            else f[i] |= 1 << j; 
        }
    }
    int score, round,ans=0;
    for (int j=0; j<1 << k; j++){
        round = 1e9;
        for (int i=0; i<n; i++){
            score = 0;
            bitset <11> trues, falses;
            trues |= t[i] & j;
            falses |= f[i] & ~j;
            // cout << trues << " " << falses << "\n";
            score += trues.count();
            score += falses.count();
            round = min(round, score);
        }

        ans = max(ans, round);
        
    }
    cout << ans << "\n";
}