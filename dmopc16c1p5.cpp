#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=5e5+5;
#define int long long
int bit[MAXSZ];

int sum(int i){
    int s = 0;
    for (; i>0; i-= (i&-i)){
        s += bit[i];
    }
    return s;
}

void update(int i){
    for (; i<MAXSZ; i+=(i&-i)){
        bit[i]++;
    }
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    int ans= 0, x;
    for (int i=0; i<n; i++){
        cin >> x;
        ans += min(sum(x-1), i-sum(x-1));

        update(x);
    }
    cout << ans << "\n";
}