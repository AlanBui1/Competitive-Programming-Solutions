#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=1e6+5;
const int INF = 1e9+5;

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 

    int n; cin >> n;

    int arr[MAXSZ]; int dp[MAXSZ];

    for (int i=0; i<n; i++) cin >> arr[i];

    for (int i=0; i<MAXSZ; i++) dp[i] = INF;

    dp[0] = -INF;

    for (int i=0; i<n; i++){
        int ind = upper_bound(dp, dp+MAXSZ, arr[i])-dp;

        if (arr[i] > dp[ind-1] && arr[i] < dp[ind]){
            dp[ind] = arr[i];
        }
    }

    for (int i=n; i>0; i--){
        if (dp[i] != INF){
            cout << i << "\n";
            break;
        }
    }
}