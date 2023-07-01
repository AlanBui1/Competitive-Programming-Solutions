#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define ll long long

ll n, m, x, bit[MAXSZ], freq[MAXSZ], v, arr[MAXSZ];
ll QL, QR;

void update(int i, int newVal, int bitc){
    if (bitc){
        for (; i < MAXSZ; i+=(i & -i)){
            bit[i] += newVal;
        }
    }
    else{
        for (; i < MAXSZ; i+=(i & -i)){
            freq[i] += newVal;
        }
    }
}

ll sum(int r, int bitc){
    ll ans = 0;

    if (bitc){
        for (; r > 0; r -= (r & -r)){
            ans += bit[r];
        }
    }
    else{
        for (; r > 0; r -= (r & -r)){
            ans += freq[r];
        }
    }
    
    return ans;
}


ll query(int L, int R, bool bitc){
    return sum(R, bitc) - sum(L-1, bitc);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> x;
        update(i, x, 1);
        update(x, 1, 0);
        arr[i] = x;
    }


    char oper;
    while (m--){
        cin >> oper;

        if (oper == 'C'){
            cin >> x >> v;
            update(x, v-arr[x], 1);
            update(arr[x], -1, 0);
            update(v, 1, 0);

            arr[x] = v;
        }

        else if (oper == 'S'){
            cin >> QL >> QR;
            cout << query(QL, QR, 1) << "\n";
        }

        else{
            cin >> QR;
            cout << query(1, QR, 0) << "\n";
        }
    }

    
}