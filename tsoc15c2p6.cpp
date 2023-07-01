#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
#define inf INT_MAX
#define ll long long
int arr[MAXSZ];

struct segTree{
    ll L, R, minVal, lazy;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R=right;
    s.lazy = 0;

    if (left == right){
        s.minVal = arr[left];
        return;
    }

    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
    s.minVal = min(cl.minVal, cr.minVal);
}

void lazyPush(int curNode){
    int L=s.L, R=s.R;

    s.minVal -= s.lazy;
    if (s.minVal < 0) s.minVal = 0;

    if (L==R){
        s.lazy = 0;
        return;
    }

    else{
        cl.lazy += s.lazy;
        cr.lazy += s.lazy;
        s.lazy = 0;
        return;
    }
}

void update(int curNode, int UL, int UR, int newVal){
    int L=s.L, R=s.R;

    if (s.lazy > 0) lazyPush(curNode);
  
    if (L> UR || R < UL) return;
    
    else if (UL <= L && R <= UR){
        s.lazy += newVal;
        lazyPush(curNode);
        return;
    }
    
    update(curNode*2, UL, UR, newVal);
    update(curNode*2+1, UL, UR, newVal);
    s.minVal = min(cl.minVal, cr.minVal);

}

int query(int curNode, int QL, int QR){
    int L=s.L, R=s.R;

    if (s.lazy > 0) lazyPush(curNode);

    if (L > QR || R < QL){
        
        return inf;
    }

    else if (QL <= L && R <= QR){
        return s.minVal;
    }

    return min(query(curNode*2, QL, QR), query(curNode*2+1, QL, QR));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1);

    int a, b, x;

    while (q--){
        cin >> a >> b >> x;
        a--; b--;
    
        update(1, a, b, x);

        cout << query(1, a, b) << " " << query(1, 0, n-1) << "\n";

 
    }

}