#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=105;

int dp[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int q=5;
    while (q--){
        int s; cin >> s;
        int n;
        for (int i=0; i<MAXSZ; i++) dp[i] = 0;
        int ans =0;
        cin >> n;

        for (int i=0; i<n; i++){
            int space, utility;

            cin >> space >> utility;
            ans =0;
            for (int k=s; k>=0; k--){
                if (k-space >= 0){
                    dp[k] = max(dp[k], dp[k-space]+utility);
                }
                ans = max(ans, dp[k]);
            }

        }
        cout << ans << "\n";

    }
}