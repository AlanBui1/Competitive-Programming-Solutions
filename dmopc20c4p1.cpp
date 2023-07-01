#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    ll n, s;
    for (int q=0; q<t; q++){
        cin >> n >> s;
        if (n ==2){
            cout << 1 << "\n";
            continue;
        }

        ll acc = (n*(n+1))/2;
        ll dif = acc-s;
        ll ans = 0;
        if (dif <= 2){
            cout << 0 << "\n";
            continue;
        }
        ans = dif/2;
        
        if (dif%2 == 0){
            ans --;
        }

        if (dif > n){
            ans -= ((dif-1)-n);
        }
        cout << ans <<  "\n";

    }
}