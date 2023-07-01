#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MAXSZ = 2e5+5;
const int MOD = 1e9+7;

int arr[MAXSZ], ans=1, term[MAXSZ];

signed main(){
    cin.sync_with_stdio(0); cin.tie(0);
    term[0] = 1;
    term[1] = 2;
    for (int i=2; i<MAXSZ; i++){
        term[i] = term[i-1]*term[i-1] + 1;
        term[i] %= MOD;
    }

    int n; cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        int cnt = 0;
        while (arr[i] %2 == 0){
            cnt++;
            arr[i] /= 2;
        }
        ans *= term[cnt] %MOD;
        ans %= MOD;
    }

    cout << ans%MOD << "\n";
}