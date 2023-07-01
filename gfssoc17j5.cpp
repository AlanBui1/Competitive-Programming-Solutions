#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
const int MAXK = 16;
const int inf = 1e9;

int dp[MAXN][MAXK]; 
int arr[MAXN][4];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    for (int i=1; i<=n; i++){
        for (int k=0; k<4; k++){
            cin >> arr[i][k];
            if (arr[i][k] == -1) arr[i][k] = -inf;
        }
    }

    int ans=-1;

    for (int i=1; i<=n; i++){
        for (int k=1; k<MAXK; k++){
            dp[i][k] = dp[i-1][k];

            for (int j=0; j<4; j++){
                if (k&(1<<j)){ //checks if j is in use in set k
                    dp[i][k] = max(dp[i][k], arr[i][j]+ dp[i-1][k^(1<<j)]);
                }
            }
            ans=max(ans, dp[i][k]);

        }
    }

    cout << ans << "\n";

}