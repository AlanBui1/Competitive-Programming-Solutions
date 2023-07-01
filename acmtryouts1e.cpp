#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 205;
const int MOD = 1e9+7;

int N, M, A[MAXSZ], B[MAXSZ];
int dp[MAXSZ][MAXSZ]; //dp[i][k] = number of ways to feed first i with k left

void solve(){
    cin >> N >> M;
    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<MAXSZ; k++){
            dp[i][k] = 0;
        }
    }
    dp[0][M] = 1;



    for (int i=1; i<=N; i++){
        cin >> A[i] >> B[i];

        for (int k=A[i]; k <= B[i]; k++){
            for (int j=k; j <= M; j++){
                dp[i][j-k] += dp[i-1][j];
                dp[i][j-k] %= MOD;
            }
        }
    }

    cout << dp[N][0] << "\n";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--){
        solve();
    }
}