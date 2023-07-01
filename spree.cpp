#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1005;

int dp[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, t;
    cin >> n >> t;
    
    for (int i=0; i<n; i++){
        int v, h; cin >> v >> h;
        
        for (int k=t; k>=0; k--){
            if (k-h >= 0){
                dp[k] = max(dp[k], dp[k-h]+v);
            }
        }
    }
    
    cout << dp[t] << "\n";
}