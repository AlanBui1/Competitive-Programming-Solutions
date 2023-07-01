#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=3005;
ll arr[MAXSZ];
ll dp[MAXSZ][MAXSZ];

ll solve(ll l, ll r){

    if (l==r) return arr[l];
    ll& cur = dp[l][r];

    if (cur != -1) return cur;

    cur = max(arr[l]-solve(l+1, r), arr[r]-solve(l, r-1));

    return cur;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;

    cout << solve(0, n-1) << "\n";

}