#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 2005;
int arr[MAXSZ], dp[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    for (int i=0; i<n; i++){
        cin >> arr[i];
        dp[i] = 1;
    } 
    sort(arr, arr+n);
    int ans = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[i]-arr[j] >= k){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans <<"\n";
}