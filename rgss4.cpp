#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int arr[n];
    for (int i=1; i<=n; i++) cin >> arr[i];

    int dp[n+5];

    for (int i=0; i<n+5; i++) dp[i] = 0;

    dp[1] = arr[1];
    int ans =dp[1];

    for (int i=2; i<=n; i++){
        int height = arr[i];
        dp[i] = height;
        for (int k=i-1; k>0; k--){
            if (height > arr[k]){
                dp[i] = max(dp[i], dp[k]+height);
            }
        }
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}