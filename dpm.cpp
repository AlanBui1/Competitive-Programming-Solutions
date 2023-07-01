#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
const int MAXN = 105;
const int MOD = 1e9+7;
#define ll long long

ll dp[MAXSZ][MAXN];
ll arr[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    memset(dp, 0, sizeof(dp));
    int n, k; cin >> n >> k;
    
    for (int i=0; i<n; i++) cin >> arr[i+1];
    dp[0][0] = 1;

    for (int i=0; i<=n; i++){ //number of kids
        for (int j=0; j<=k; j++){ //number of candies
            if (i==0 && j == 0) continue;
            if (j == 0 && i != 0){
                dp[j][i] = 1; 
                continue;
            }

            if (i == 0 && j != 0){
                dp[j][i] = 1;
                continue;
            }

            dp[j][i] = (dp[j][i]+MOD)%MOD;
            if (j-arr[i]-1 < 0){
                dp[j][i] += dp[j][i-1];
            }
            else dp[j][i] += (dp[j][i-1] - dp[j-arr[i]-1][i-1]);
            dp[j][i] = (dp[j][i]+dp[j-1][i]+MOD)%MOD;
        }
    }

    cout << (dp[k][n]-dp[k-1][n]+MOD)%MOD << "\n";
}