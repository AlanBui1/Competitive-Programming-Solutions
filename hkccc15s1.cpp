#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXSZ = 1e5+5;
const int MOD = 1e9+7;

ll arr[MAXSZ], n, m;

ll bsearch(ll x){
    ll lo = 0, hi = n-1, ret = n;
    while (lo <= hi){
        ll mid = (lo+hi)/2;

        if (arr[mid] > x){
            ret = mid;
            hi = mid-1;
        }
        else lo = mid+1;
    }
    return ret;
}



int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    ll ans = 0;
    sort(arr, arr+n);

    for (int i=0; i<n; i++){
        ans += bsearch(m - arr[i]);
        if (arr[i]*2 <= m) ans--;
    }

    cout << ans/2%MOD << "\n";
}