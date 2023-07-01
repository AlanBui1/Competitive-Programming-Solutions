#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
#define ll long long
ll n, m, k, a, b;
ll arr[MAXSZ];

bool works(ll w){
    for (int i=0; i<=n-w; i++){
        if (arr[i+w]-arr[i] >= k){
            return 1;
        }
    }
    return 0;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for (int i=0; i<m; i++){
        cin >> a >> b;
        arr[a]--; arr[b+1]++;
    }

    for (int i=1; i<=n; i++){
        arr[i] += arr[i-1];
    }

    for (int i=1; i<=n; i++){
        arr[i] += arr[i-1]+m;
        // cout << arr[i] << " ";
    }
    // cout << "\n";

    ll L = 0, R = n;
    ll ans = 1e18;

    while (L <= R){
        ll mid = (L+R)/2;
        if (works(mid)){
            ans = min(ans, mid);
            R = mid-1;
        }
        else{
            L = mid+1;
        }
    }

    if (ans >= 1e18){
        cout << -1 << "\n";
    }
    else if (k == 0){
        cout << 0 << "\n";
    }
    else{
        cout << ans << "\n";
    }
}