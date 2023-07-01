#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;
const int INF=1e9+5;
int arr[MAXSZ], dp[MAXSZ];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    string s;
    cin >> s;

    int n = s.length();
    for (int i=0; i<n; i++){
        arr[i] = s[i] - 'a' + 1;
     
    }


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
            cout << 26-i << "\n";
            return 0;
        }
    }


}