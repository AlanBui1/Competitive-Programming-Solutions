#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    ll x, y;
    cin >> x >> y;

    if (x > y){
        ll re = y;
        y = x;
        x = re;
    }

    ll r;
    cin >> r;
    ll a, b;
    ll tot=0;
    
    for (ll i=0; i<r; i++){
        cin >> a >> b;

        if (a > y || b < x){
            continue;
        }
        else{
            tot += b-a;
            tot++;
            if (a<x){
                tot -= x-a;
            }
            if (b>y){
                tot -= b-y;
            }
        }
    }
    
    cout << tot << "\n";
}