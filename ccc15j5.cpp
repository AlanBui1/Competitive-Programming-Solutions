#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nax = 300;

int dp[nax][nax][nax];

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;
    if (K == N || K == 1){
        cout<<1 << "\n";
        return 0;
    }

    for (int i=1; i<=N; i++){
        dp[1][i][i] = 1;
    }

    for (int i=2; i<=K; i++){
        for (int j=1; j<=N; j++){
            for (int k=1; k<=N; k++){

                for (int _ = 1; _ <= j; _++){
                    if (k - j < 0) break;
                    dp[i][j][k] += dp[i-1][_][k-j];
                }
                //cout << i <<" " << j << " " << k << " " << dp[i][j][k] << "\n";
            }
        }
    }

    int ans =0 ;
    for (int i=0; i<=N; i++){
        ans += dp[K][i][N];
    }
    cout << ans << "\n";
}