#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
#define f first
#define s second
#define ll long long
ll bit[MAXSZ];
int n, q;

void update(int r, int v){
    for (int i=r; i<=n; i+= (i&-i)){
        bit[i]+=v;
    }
}

ll query(int r){
    ll tot=0;

    for (int i=r; i>0; i -= i&-i){
        tot += bit[i];
    }

    return tot;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    vector <pair <ll, ll>> arr;
    for (int i=0; i<n; i++){
        ll v; cin >> v;
        arr.push_back({v, i});
    }

    ll add[q];
    ll minus[q];
    vector <pair <ll, pair <ll, pair <ll, ll>>>> queries;

    int l, r, x;
    for (int i=0; i<q; i++){
        cin >> l >> r >> x;
        queries.push_back({x, {l, {r, i}}});
    }

    sort(arr.begin(), arr.end());
    sort(queries.begin(), queries.end());

    ll X, L, R, I;
    ll curTree = 0;
    for (int i=0; i<q; i++){
        X = queries[i].f;
        L = queries[i].s.f;
        R = queries[i].s.s.f;
        I = queries[i].s.s.s;

        if (curTree < n){
            while (arr[curTree].f < X && curTree < n){
                update(arr[curTree].s+1, arr[curTree].f);
                curTree ++;
                if (curTree == n) break;
                
            }
        }
        minus[I] = query(R) - query(L-1);
    }

    for (int i=0; i<MAXSZ; i++) bit[i]=0;
    curTree=n-1;

    for (int i=q-1; i>=0; i--){
        X = queries[i].f;
        L = queries[i].s.f;
        R = queries[i].s.s.f;
        I = queries[i].s.s.s;

        if (curTree >= 0){
            while (arr[curTree].f >= X && curTree > -1){
                update(arr[curTree].s+1, arr[curTree].f);
                curTree --;
                
                if (curTree == -1) break;
                
            }
        }
        add[I] = query(R) - query(L-1);
    }

    for (int i=0; i<q; i++) cout << add[i]-minus[i] << "\n";

}