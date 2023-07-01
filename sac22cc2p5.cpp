#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=1e6+5;

ll ebit[MAXSZ], obit[MAXSZ];
ll n, q, p, j, l, r;

bool onEven(int v){
    return (v%2);
}

void eupdate(int r, int v){
    for (int i=r; i<=n; i+= i&-i){
        ebit[i]+=v;
    }

}

void oupdate(int r, int v){
    for (int i=r; i<=n; i+= i&-i){
        obit[i]+=v;
    }
}

ll esum(int l, int r){
    ll tot=0;
    for (; r>0; r -= (r&-r)){
        tot +=ebit[r];
    }
    l--;
    for (; l>0; l-=(l&-l)){
        tot -= ebit[l];
    }
    return tot;
}

ll osum(int l, int r){
    ll tot=0;
    for (; r>0; r -= (r&-r)){
        tot +=obit[r];
    }
    l--;
    for (; l>0; l-=(l&-l)){
        tot -= obit[l];
    }
    return tot;
}


int arr[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        if (onEven(i)){
            eupdate(i, arr[i]);
        }
        else{
            oupdate(i, arr[i]);
        }
    }

    while (q--){
        int oper; cin >> oper;

        if (oper == 1){
            int i;
            cin >> i >> j;
            if (onEven(i)){
                eupdate(i, j-arr[i]);
            }
            else{
                oupdate(i, j-arr[i]);
            }
            arr[i] = j;
        }

        else{
            cin >> l >> r;

            if (onEven(l)){
                cout << esum(l, r) << "\n";
            }
            else{
                cout << osum(l, r) << "\n";
            }
        }
    }
}