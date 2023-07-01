#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;

int dp[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=0; i<n; i++){
        int t, w; cin >> t >> w;

        dp[t] = max(dp[t], w);
    }

    for (int i=1; i<MAXSZ; i++){
        dp[i] = max(dp[i], dp[i-1]);
    }

    int q; cin >> q;

    while (q--){
        int T; cin >> T;
        cout << dp[T] << "\n";
    }
}