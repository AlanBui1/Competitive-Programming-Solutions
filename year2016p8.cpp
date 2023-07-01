#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXSZ=1e5+5;

#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

const int inf = 1e6;

struct SECT{
    int LL, RR, val;
}nothing;

struct node{
    int L, R;
    SECT SEG, SUF, PREF, SUM;
    bool destroy, build;
}seg[MAXSZ*4];

void clr(int curNode){
    s.destroy = 0; s.build = 0;
    s.SEG = s.SUF = s.PREF = s.SUM = nothing;
}

SECT f(SECT x, SECT y){
    if (y.val > x.val) return y;
    if (y.val == x.val){
        if (x.LL > y.LL) return y;
    }
    return x;
}

void pushUp(int curNode){
    SECT M; M.val = cl.SUF.val+cr.PREF.val; M.LL = cl.SUF.LL; M.RR = cr.PREF.RR;
    s.SEG = f(cl.SEG, f(cr.SEG, M));

    SECT left; left.val = cl.SUM.val + cr.PREF.val; left.LL = cl.SUM.LL; left.RR = cr.PREF.RR;
    s.PREF = f(cl.PREF, left);

    SECT right; right.val = cr.SUM.val + cl.SUF.val; right.LL = cl.SUF.LL; right.RR = cr.SUM.RR;
    s.SUF = f(cr.SUF, right);

    s.SUM.val = cl.SUM.val+cr.SUM.val; s.SUM.LL = cl.SUM.LL; s.SUM.RR = cr.SUM.RR;
}

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;
    s.destroy = 0; s.build = 0;

    if (left == right){
        s.SEG.LL = s.SEG.RR = s.SUF.LL = s.SUF.RR = s.PREF.LL = s.PREF.RR = s.SUM.LL = s.SUM.RR = left;
        s.SEG.val = s.PREF.val = s.SUF.val = s.SUM.val = -inf;
        return;
    }

    int mid = (left+right)/2;

    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);

    pushUp(curNode);

}

void lazyPush(int curNode){
    if (!s.destroy && !s.build) return;
    int L = s.L, R = s.R;

    if (s.destroy){
        clr(curNode);
        s.SEG.LL = s.SUF.LL = s.PREF.LL = s.SUM.LL = L;
        s.SEG.RR = s.SUF.RR = s.PREF.RR = s.SUM.RR = R;
        if (L == R){
            return;
        }
        clr(curNode*2); clr(curNode*2+1);
        cl.destroy = 1; cr.destroy = 1;
        return;
    }

    clr(curNode);
    s.SEG.LL = s.SUF.LL = s.PREF.LL = s.SUM.LL = L;
    s.SEG.RR = s.SUF.RR = s.PREF.RR = s.SUM.RR = R;
    s.SEG.val = s.PREF.val = s.SUF.val = s.SUM.val = R-L+1;
    if (L == R) return;

    clr(curNode*2); clr(curNode*2+1);
    cl.build = 1; cr.build = 1;
    return;
}

void upd(int curNode, int UL, int UR, bool destroy){
    int L = s.L, R = s.R;

    lazyPush(curNode);

    if (L > UR || R < UL) return;
    if (UL <= L && R <= UR){
        clr(curNode);
        if (destroy){
            s.destroy = 1;
        }
        else{
            s.build = 1;
        }
        lazyPush(curNode);
        return;
    }

    upd(curNode*2, UL, UR, destroy);
    upd(curNode*2+1, UL, UR, destroy);

    pushUp(curNode);
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);
    nothing.val = -inf;

    int n, q, op, l, r; cin >> n >> q;

    buildTree(1, 0, n);

    while (q--){

        cin >> op;
        if (op == 0){
            cin >> l >> r;
            upd(1, l, r, 1);
        }
        else if (op == 1){
            cin >> l >> r;
            upd(1, l, r, 0);
        }
        else{
            upd(1, seg[1].SEG.LL, seg[1].SEG.RR, 1);
        }

        if (op != 2){
            lazyPush(1);
            if (seg[1].SEG.val > 0) cout << seg[1].SEG.val << "\n";
            else cout << 0 << "\n";
        }
    }

}