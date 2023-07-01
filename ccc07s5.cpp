#include <bits/stdc++.h>
using namespace std;
#define ms(a, b) memset(a, b, sizeof(a))
const int MAXSZ=30005;
int dp[505][MAXSZ];
int psa[MAXSZ];

int sum(int a, int b){
    return psa[b]-psa[a-1];
}

int main() {

    cin.sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    int n, b, w; 
    while (t--){

        ms(dp, 0);
        ms(psa, 0);
        cin >> n >> b >> w;


        for (int i=1; i<=n; i++){
            cin >> psa[i];
            psa[i] += psa[i-1];
        }

        for (int i=1; i<=b; i++){
            for (int k=n; k>0; k--){
                dp[i][k] = max(dp[i][k+1], sum(k, min(n, k+w-1))+dp[i-1][min(n+1,k+w)]);
            }
        }

        cout << dp[b][1] << "\n";

    }
    
}