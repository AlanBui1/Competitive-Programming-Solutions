#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int inf = 1e9;


int main() {
    // cin.sync_with_stdio(0); cin.tie(0);

    int n; scan(n);

    int coins[n], num[n];

    for (int i=0; i<n; i++) scan(coins[i]);
    for (int i=0; i<n; i++) scan(num[i]);

    int c; scan(c);

    int dp[c+1]; 
     
    for (int i=0; i<c+1; i++) dp[i] = inf;
    dp[0] = 0;
    for (int i=0; i<n; i++){
        if (dp[c] <= 1) {
            cout << dp[c] << "\n";
            return 0;
        }
        for (int k=c; k>= 0; k--){
            for (int j=1; j<num[i]+1; j++){
                int coin = j*coins[i];
                if (coin > c) break;
                if (k-coin >= 0){
                    dp[k] = min(dp[k], dp[k-coin]+j);
                }
            }
        }
    }
    cout << dp[c] <<"\n";
}