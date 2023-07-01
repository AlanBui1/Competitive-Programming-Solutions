#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=3005;

double arr[MAXSZ];
double dp[MAXSZ][MAXSZ];

int main() {
    // cout << sizeof(dp);
    // cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    dp[0][0] = 1;

    for (int i=1; i<=n; i++){
        dp[0][i] = 1-arr[i];
        dp[0][i] *= dp[0][i-1];
        
    }

    for (int i=1; i<=n; i++){
        for (int k=1; k<=n; k++){

            if (i> k){
                dp[i][k] = 0;
                continue;
            }
            if (i==k){
                dp[i][k] = arr[k]*dp[i-1][k-1];
                continue;
            }
            dp[i][k] = arr[k]*dp[i-1][k-1];
            dp[i][k] += (1-arr[k])*dp[i][k-1];
        }
    }



    double ans=0;
    for (int i=n; i>n/2; i--){
        ans += dp[i][n];
    }
    cout << setprecision(10) << ans << "\n";

}