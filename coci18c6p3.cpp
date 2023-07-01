#include <bits/stdc++.h>
using namespace std;

const int nax = 505;

int N, M, K, dp[nax][nax], P[nax], B[nax];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i=1; i<=N; i++){
        cin >> P[i];
    }

    for (int i=0;i<=M; i++){
        cin >> B[i];
    }

    for (int i=1; i<=N; i++){
        for (int j=0; j<=K; j++){
            int W = 0;
            for (int k=0; k<=j; k++){
                W = max(W, B[min(M, P[i] + k)] + dp[i-1][j - k]);
            }
            dp[i][j] = W;
            //cout << dp[i][j] << " ";
        }
        //cout << "\n";
    }

    cout << dp[N][K] << "\n";

}