#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll p, y, t;

ll money(ll x){
    ll curMoney = 0;
    for (int i=0; i<y; i++){
        curMoney += x;
        curMoney *= 100+p;
        curMoney /= 100;
        // cout << curMoney << "\n";
        if (curMoney >= t) return curMoney;
    }
    return curMoney;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> p >> y >> t;

    ll lo = 0, hi = t, ans = t;

    while (lo <= hi){
        ll mid = (lo+hi)/2;

        ll val = money(mid);

        if (val >= t){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }

    cout << ans << "\n";
}