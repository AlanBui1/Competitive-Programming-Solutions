#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

#define ll long long
int n, k, q;

struct segTree{
    int L, R;
    ll lazy, killpower;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;
    s.lazy = 0; s.killpower = 0; 

    if (left != right){
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
    }
}

void lazyPush(int curNode){
    int L=s.L, R=s.R;

    if (s.lazy <= 0) return;

    s.killpower += s.lazy;
    
    if (L==R){
        s.lazy = 0;
        return;
    }

    cl.lazy += s.lazy;
    cr.lazy += s.lazy;
    s.lazy = 0;
    return;
}

void update(int curNode, int UL, int UR, int newVal){
    int L=s.L, R=s.R;

    lazyPush(curNode);

    if (L > UR || R < UL) return;

    if (UL <= L && R <= UR){
        s.lazy += newVal;
        lazyPush(curNode);
    }

    else{
        update(curNode*2, UL, UR, newVal);
        update(curNode*2+1, UL, UR, newVal);

        s.killpower = max(cl.killpower, cr.killpower);
    }
}

ll query(int curNode, int QL, int QR){
    int L=s.L, R=s.R;

    lazyPush(curNode);

    if (L > QR || R < QL) return 0;

    if (QL <= L && R <= QR) return s.killpower;

    return max(query(curNode*2, QL, QR), query(curNode*2+1, QL, QR));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> k >> q;
    int p, v, l, r;

    buildTree(1, 0,2e5+1);

    while (q--){
        int oper; cin >> oper;
        if (oper == 0){
            cin >> p >> v;
            update(1, max(0, p-k+1), p, v);
        }

        else{
            cin >> l >> r;
            cout << query(1, l, r) << "\n";
        }
    }

}