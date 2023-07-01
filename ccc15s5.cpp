#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 3005;
const int MAXM = 105;

int A[MAXSZ], N, M, B[MAXM];
int dp[MAXSZ][2][MAXM][MAXM]; //dp[i][can][L][R]

int solve(int curAPie, int canTake, int left, int right){
    //cout << curAPie << " " << canTake << " " << left << " " << right << "\n";
    if (curAPie > N && left > right) return 0;
    if (dp[curAPie][canTake][left][right] != -1) return dp[curAPie][canTake][left][right];

    if (curAPie <= N) dp[curAPie][canTake][left][right] = solve(curAPie+1, 1, left, right);
    if (left <= right) dp[curAPie][canTake][left][right] = max(dp[curAPie][canTake][left][right], solve(curAPie, 1, left+1, right));

    if (canTake){
        dp[curAPie][canTake][left][right] = max(dp[curAPie][canTake][left][right], A[curAPie] + solve(curAPie+1, 0, left, right));
        if (left <= right) dp[curAPie][canTake][left][right] = max(dp[curAPie][canTake][left][right], B[right] + solve(curAPie, 0, left, right-1));
    }

    return dp[curAPie][canTake][left][right];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> A[i];
    }

    cin >> M;
    for (int i=1; i<=M; i++){
        cin >> B[i];
    }

    sort(B, B+M+1);

    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<2; k++){
            for (int j=0; j<MAXM; j++){
                for (int l=0; l<MAXM; l++){
                    dp[i][k][j][l] = -1;
                }
            }
        }
    }

    cout << solve(1, 1, 1, M) << "\n";
}