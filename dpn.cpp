#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=405;

ll inf = 1e18;
ll arr[MAXSZ];
ll dp[MAXSZ][MAXSZ];
ll n;
ll solve(ll L, ll R){
    if (L==R){
        dp[L][R] = 0;
        return 0;
    } 
    
    ll& cur = dp[L][R];
    if (cur != inf) return cur;

    ll s =0;
    
    for (int i=L; i<R; i++){
        
        cur = min(cur, solve(L, i)+solve(i+1, R));
        s+=arr[i];
    } 
    cur += arr[R]+s;
    return cur;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    memset(dp, inf, sizeof(dp));
    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<MAXSZ; k++){
            dp[i][k] = inf;
        }
    }
    cout << solve(0, n-1) << "\n";
}