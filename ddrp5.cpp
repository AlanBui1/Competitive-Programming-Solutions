#include <bits/stdc++.h>
using namespace std;

#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
#define f first
#define se second

const int MAXSZ = 1e6+5;
const int inf = 2e9+5;
const int ninf = -2e9;
int arr[MAXSZ];
int n, q;

struct node{
    int L, R;
    int minVal, maxVal, secondMin, secondMax;
}seg[MAXSZ*4];

struct Q{
    int lo, hi;
}qs[MAXSZ];

int val(int x){
    return ceil(x/sqrt(n));
}

void pushUp(int curNode){
    if (cl.minVal < cr.minVal){
        s.minVal = cl.minVal;
        s.secondMin = min(cr.minVal, min(cl.secondMin, cr.secondMin));
    }

    else{
        s.minVal = cr.minVal;
        s.secondMin = min(cl.minVal, min(cl.secondMin, cr.secondMin));
    }

    if (cl.maxVal > cr.maxVal){
        s.maxVal = cl.maxVal;
        s.secondMax = max(cr.maxVal, max(cl.secondMax, cr.secondMax));
    }

    else{
        s.maxVal = cr.maxVal;
        s.secondMax = max(cl.maxVal, max(cl.secondMax, cr.secondMax));
    }
}

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.minVal = arr[left];
        s.maxVal = arr[left];
        s.secondMin = inf;
        s.secondMax = ninf;
        return;
    }

    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);

    pushUp(curNode);
}

void update(int curNode, int idx, int newVal){
    int L = s.L, R = s.R;

    if (L > idx || R < idx) return;
    if (L == R && L == idx){
        s.minVal = newVal;
        s.maxVal = newVal;
        return;
    }

    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);
    pushUp(curNode);
}

pair <int, int> queryMin(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL) {
        return {inf, inf};
    }

    if (QL <= L && R <= QR){
        return {s.minVal, s.secondMin};
    }

    pair <int, int> lhs = queryMin(curNode*2, QL, QR), rhs = queryMin(curNode*2+1, QL, QR);

    if (lhs.f < rhs.f){
        return {lhs.f, min(rhs.f, min(rhs.se, lhs.se))};
    }
    return {rhs.f, min(lhs.f, min(rhs.se, lhs.se))};
}

pair <int, int> queryMax(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL) {
        return {ninf, ninf};
    }

    if (QL <= L && R <= QR){
        return {s.maxVal, s.secondMax};
    }

    pair <int, int> lhs = queryMax(curNode*2, QL, QR), rhs = queryMax(curNode*2+1, QL, QR);

    if (lhs.f > rhs.f){
        return {lhs.f, max(rhs.f, max(rhs.se, lhs.se))};
    }
    return {rhs.f, max(lhs.f, max(rhs.se, lhs.se))};
}


int lastAns=0;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    qs[1].lo = 1;
    int cur = 1;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        if (val(i) != val(i-1) && i != 1){
            qs[cur].hi = i-1;
            cur++;
            qs[cur].lo = i;
        }
    }
    if (qs[cur].hi == 0) qs[cur].hi = n;

    buildTree(1, 1, n);

    while (q--){
        int oper, l, r;
        cin >> oper >> l >> r;
        l ^= lastAns; r ^= lastAns;

        if (oper == 1){
            update(1, l, r);
        }
        else if (oper == 2){
            pair <int, int> ans = queryMin(1, qs[l].lo, qs[r].hi);
            cout << ans.f+ans.se << "\n";
            lastAns = ans.f+ans.se;
        }
        else{
            pair <int, int> ans = queryMax(1, qs[l].lo, qs[r].hi);
            cout << ans.f+ans.se << "\n";
            lastAns = ans.f+ans.se;
        }
    }
    //pair <int, int> ans = queryMin(1, 1, 4);
    //cout << ans.f +ans.se << "\n";

}