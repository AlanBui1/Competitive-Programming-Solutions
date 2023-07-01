#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=104;

int arr[MAXSZ];
int dp[MAXSZ][MAXSZ];

int solve(int L, int R){
    if (dp[L][R] != -1) return dp[L][R];
    if (L == R){
        return arr[L];
    }

    int ret = 0;
    ret = max(-solve(L+1, R)+arr[L], -solve(L, R-1)+arr[R]);

    dp[L][R] = ret;
    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int tot = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        tot += arr[i];
    }
    memset(dp, -1, sizeof(dp));
    int score = solve(0, n-1);

    int p1 = (score+tot)/2;
    cout << p1 << " " << tot-p1 << "\n";
}