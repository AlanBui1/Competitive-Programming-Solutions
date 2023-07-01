#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=4e5;
const int inc = 160000;
#define ll long long
ll bit[MAXSZ], arr[inc], orig[inc];
void update(ll i, ll v){
    for (; i<MAXSZ; i+=(i&-i)){
        bit[i] += v;
    }
}
ll sum(int i){
    ll s=0;
    for (; i>0; i-=(i&-i)){
        s+=bit[i];
    }
    return s;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    ll n; cin >> n;
    ll op;
    for (int i=1; i<=n; i++){
        cin >> op;
        if (op == 1){
            arr[i]++;
        }
        else{
            arr[i]--;
        }
        orig[i] = arr[i];
    }
    ll want = 0, ans =0;

    for (int i=1; i<=n; i++){
        arr[i] += arr[i-1];
        update(arr[i]+inc, 1);
        if (arr[i] > 0) ans++;
        // cout << arr[i] << " ";
    }
    // cout << "\n";

    for (int i=1; i<n; i++){
        if (orig[i] == 1){
            want++;
        }
        else{
            want--;
        }
        update(arr[i]+inc, -1);
        ans += max(0ll,n-i-sum(want+inc));
        // cout << n-i-sum(want+inc) << "\n";
    }

    cout << ans << "\n";
    
}