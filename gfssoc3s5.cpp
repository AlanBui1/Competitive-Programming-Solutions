#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nax = 1e5+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

int arr[nax];
struct segTree{
    int L, R, pref, suf, OR, best;
}seg[nax*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.pref = arr[left];
        s.suf = arr[left];
        s.OR = arr[left];
        s.best = arr[left];
    }

    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        s.pref = max(cl.pref, cl.OR | cr.pref);
        s.suf = max(cr.suf, cr.OR | cl.suf);
        s.OR = cl.OR | cr.OR;
        s.best = max(cl.best, max(cr.best, cl.suf|cr.pref));
    }
}

void update(int curNode, int idx, int newVal){
    int L=s.L, R=s.R;

    if (L>idx || R < idx) return;
    if (L==R && L==idx){
        s.pref = newVal;
        s.suf = newVal;
        s.OR = newVal;
        s.best = newVal;
    }
    else{
        update(curNode*2, idx, newVal); update(curNode*2+1, idx, newVal);
        s.pref = max(cl.pref, cl.OR | cr.pref);
        s.suf = max(cr.suf, cr.OR | cl.suf);
        s.OR = cl.OR | cr.OR;
        s.best = max(cl.best, max(cr.best, cl.suf|cr.pref));
    }
}

__int32_t main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for (int i=0; i<n; i++){
        cin >> arr[i];

    } 
    buildTree(1, 0, n-1);
    int i, x;
    while (q--){
        cin >> i >> x;

        update(1, i-1, x);
        cout << seg[1].best << "\n";
    }

}