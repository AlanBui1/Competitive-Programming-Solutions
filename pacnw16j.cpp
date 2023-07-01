#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
#define ll long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const ll inf = 1e18;

struct node{
    ll L, R, val;
}seg[MAXSZ*4];

ll arr[MAXSZ];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.val = arr[left];
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left,mid);
        buildTree(curNode*2+1, mid+1, right);
        s.val = min(cl.val, cr.val);
    }
}

ll query(ll curNode, ll QL, ll QR, ll want){
    int L = s.L, R = s.R;

    if (L > QR || R < QL || s.val > want) return inf;
    if (L == R){
        return L;
    }
    if (QL <= L && R <= QR){
        if (cl.val <= want) return query(curNode*2, QL, QR, want);
        return query(curNode*2+1, QL, QR, want);
    }
    return min(query(curNode*2, QL, QR, want), query(curNode*2+1, QL, QR, want));
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for (int i=0; i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1);

    while (q--){
        ll v, l, r; cin >> v >> l >> r; l--; r--;

        ll L = query(1, l, r, v), R = r;

        while (L <= R){
            v %= arr[L];
            L = query(1, L, R, v);
        }
        cout << v << "\n";
    }

}