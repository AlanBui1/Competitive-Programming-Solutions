#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define f first
#define s second

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n;
    pair <int, pair <int, int>> arr[MAXSZ];

    memset(arr, 0, sizeof(arr));

    cin >> n;

    for (int i=1; i<=n; i++) cin >> arr[i].f >> arr[i].s.f >> arr[i].s.s;

    int dp[MAXSZ][3];

    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<3; k++){
            dp[i][k] = 0;
        }
    }

    dp[1][0] = arr[1].f;
    dp[1][1] = arr[1].s.f;
    dp[1][2] = arr[1].s.s;

    for (int i=2; i<=n; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + arr[i].f;
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + arr[i].s.f;
        dp[i][2] = max(dp[i-1][1], dp[i-1][0]) + arr[i].s.s;
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << "\n";
}