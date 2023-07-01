#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXK = 1 << 19;
const ll inf = 1e18;
ll n, dp[MAXK];
bool used[MAXK];
ll arr[19], pie[19];

int solve(int curP, int mask){

    if (curP >= n) return 0;
    if (used[mask]) return dp[mask];

    used[mask] = true;

    ll& ret = dp[mask];

    for (int i=0; i<n; i++){
        if (!(mask & (1<<i))) ret = max(ret, (arr[i]*pie[(i+curP)%n]) + solve(curP+1, mask|(1<<i)));
    }
  
    return dp[mask];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    for (int i=0; i<MAXK; i++)dp[i] = -inf;
    for (int i=0; i<n; i++){
        cin >> pie[i];
    }

    cout << solve(0,0) << "\n";

}