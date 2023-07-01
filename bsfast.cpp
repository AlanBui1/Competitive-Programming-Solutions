#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const int inf = 1e9;
struct segTree{
    int L, R, minVal;
}seg[MAXSZ*4];
int arr[MAXSZ];
int ans;
int lastAns=0;
void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.minVal = arr[left];
        return;
    }
    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
    s.minVal = min(cl.minVal, cr.minVal);
}

void update(int curNode, int idx, int newVal){
    int L=s.L, R =s.R;

    if (L > idx || R< idx) return;

    else if (L== R && L==idx){
        s.minVal = newVal;
        return;
    }

    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);
    s.minVal = min(cl.minVal, cr.minVal);
}

void query(int curNode, int QL, int QR, int K){
    int L = s.L, R = s.R;
    if (R < QL || L > QR || s.minVal >= K || L >= ans) return;
    // if (R < QL || L > QR ) return;

    if (L==R && QL <= L && R <= QR && s.minVal < K){
        ans = min(ans, L);
        return;
    }

    else if (L != R && QL <= L && R <= QR){
        if (cl.minVal < K) query(curNode*2, QL, QR, K);
        else query(curNode*2+1, QL, QR, K);
    }
    else {
        query(curNode*2, QL, QR, K);
        query(curNode*2+1, QL, QR, K);
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1);

    int oper, p, l, r, x, k;

    while (q--){
        cin >> oper;
        if (oper == 1){
            cin >> p >> x;
            p = p^lastAns;
            x = x^lastAns;
            update(1, p-1, x);
        }
        else{
            cin >> l >> r >> k;
            l = l^lastAns;
            r = r^lastAns;
            k = k^lastAns;
            ans = inf;
            query(1, l-1, r-1, k);
            cout << ans+1 << "\n";
            lastAns = ans+1;
        }
    } 
}