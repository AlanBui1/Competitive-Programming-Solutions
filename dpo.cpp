#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXSZ = (1 << 21);
const int MOD = 1e9+7;

int n;
bool grid[21][21];
int dp[MAXSZ+5];

int solve(int cur, int boys, int girls){
    int ret = 0;

    if (dp[girls] != -1){
        return dp[girls];
    }

    if (girls == (1 << n) - 1){
        return dp[girls] = 1;
    }

    if (cur >= n){
        return 0;
    }

    if (boys & (1 << cur)){
        return solve(cur+1, boys, girls) % MOD;
    }

    for (int i=0; i<n; i++){
        if (girls & (1 << i)){
            continue;
        }

        if (grid[i][cur]){
            ret += solve(cur+1, boys ^ (1 << cur), girls ^ (1 << i));
            ret %= MOD;
        }
    }

    return dp[girls] = ret % MOD;
}



int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            cin >> grid[i][k];
        }
    }

    for (int i=0; i<=MAXSZ; i++){
        dp[i] = -1;
    }

    cout << solve(0, 0, 0) % MOD << "\n";
}