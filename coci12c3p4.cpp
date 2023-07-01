#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXSZ = 1e5+5;
const ll inf = 1e18;

ll arr[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    ll lo = 0, hi = inf, ans = inf;

    while (lo <= hi){
        ll mid= (lo+hi)/2;
        ll val = 0;

        for (int i=0; i<n; i++){
            val += mid/arr[i];
        }

        if (val >= m){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }


    }

    cout << ans << "\n";


}