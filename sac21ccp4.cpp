#include <bits/stdc++.h>

using namespace std;
const int MAXSZ=1e6+5;
#define ll long long

ll arr[MAXSZ];


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, q; cin >>n >> q;
    for (int i=1; i<=n; i++) cin >> arr[i];
    int L, R;
    for (int i=1; i<=n; i++){
        arr[i] += arr[i-1];
    }
    while (q--){
        cin >> L >> R;
        cout << (arr[R] - arr[L-1])/(R-L+1) << "\n";
    }
    return 0;
}