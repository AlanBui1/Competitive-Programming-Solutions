#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXSZ = 1005;
const ll MOD = 1e10;

ll arr1[MAXSZ], arr2[MAXSZ];

ll gcd(ll a, ll b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    ll n, m;
    cin >> n;
    for (int i=0; i<n; i++) cin >> arr1[i];
    cin >> m;
    for (int k=0; k<m; k++) cin >> arr2[k];

    ll ans = 1;
    bool flag = 0;

    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            ll g = gcd(arr1[i], arr2[k]);
            ans *= g;
            arr1[i] /= g;
            arr2[k] /= g;

            if (ans > MOD-1){
                flag = 1;
                ans %= MOD;
            }
        }
    }
    string s = to_string(ans);
    ll len = s.length();
    if (flag){
        while (s.length() < 9){
            s = "0"+s;
        }
    }

    cout << s.substr(max(0ll, len-9), len) << "\n";

}