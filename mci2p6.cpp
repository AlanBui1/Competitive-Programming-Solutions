#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = (1 << 22);

int dp[MAXSZ];
int n, k;
int heights[25];

bool solve(int mask, int curHeight){
    if (dp[mask] != -1) return dp[mask];

    dp[mask] = 0;
    for (int i=0; i<n; i++){
        if (mask & (1 << i) || curHeight + heights[i] > k){
            continue;
        }
        dp[mask] |= 1^(solve(mask ^ (1 << i), curHeight + heights[i]));
    }

    return dp[mask];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> heights[i];
    }
    for (int i=0; i<MAXSZ; i++){
        dp[i] = -1;
    }

    cout << (solve(0, 0) ? "win\n" : "lose\n");
}