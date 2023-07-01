#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;
#define ll long long

ll arr[MAXSZ];
map <ll, ll> conv;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    ll n, m, q;

    cin >>n >>m >> q;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        conv[arr[i]] = i;
       // cout << arr[i] << " " << i << "\n";
        arr[i] += arr[i-1];
    }

    while (q--){
        ll a, b; cin >> a >> b;

        ll val = arr[conv[b]] - arr[conv[a] -1];
        //cout << conv[a] << " " << conv[b] << " ";
        //cout << val << "\n";
        if (m <= (val/2)){
            cout << "Enough\n";
        }

        else cout << "Not enough\n";
    }

}