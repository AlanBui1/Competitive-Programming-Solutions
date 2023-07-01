#include <bits/stdc++.h>
using namespace std;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
#define ll long long
const int MAXSZ=1e5+5;
const ll inf = 1e17;
int arr[MAXSZ];
struct segTree{
    ll L, R, SUM, PREF, SEG, SUF;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.SEG = arr[left];
        s.SUM = arr[left];
        s.PREF = arr[left];
        s.SUF = arr[left];
        return;
    }

    int mid = (left+right)/2;
    buildTree(curNode*2, left ,mid);
    buildTree(curNode*2+1, mid+1, right);

    s.SUM = cl.SUM + cr.SUM;
    s.PREF = max(cl.PREF, cl.SUM+cr.PREF);
    s.SUF = max(cr.SUF, cr.SUM+cl.SUF);
    s.SEG = max(max(cl.SEG, cr.SEG), cl.SUF+cr.PREF);
}

void update(int curNode, int idx, int newVal){
    int L=s.L, R=s.R;

    if (L > idx || R < idx) return;

    else if (L==R && L==idx){
        s.SEG = newVal;
        s.SUM = newVal;
        s.PREF =newVal;
        s.SUF = newVal;
        return;
    }

    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);

    s.SUM = cl.SUM + cr.SUM;
    s.PREF = max(cl.PREF, cl.SUM+cr.PREF);
    s.SUF = max(cr.SUF, cr.SUM+cl.SUF);
    s.SEG = max(max(cl.SEG, cr.SEG), cl.SUF+cr.PREF);
}

segTree query(int curNode, int QL, int QR){
    int L=s.L, R=s.R;

    if (L > QR || R < QL){
        segTree vals;
        vals.SUM=-inf; vals.PREF=-inf; vals.SUF=-inf; vals.SEG=-inf;
        return vals;
    }

    else if (QL <= L && R <= QR){
        return seg[curNode];
    }

    segTree lhs = query(curNode*2, QL, QR), rhs = query(curNode*2+1, QL, QR);
    segTree vals;
    vals.SUM = lhs.SUM+rhs.SUM; vals.PREF = max(lhs.PREF, lhs.SUM+rhs.PREF); vals.SUF = max(rhs.SUF, rhs.SUM+lhs.SUF);
    vals.SEG = max(max(lhs.SEG, rhs.SEG), lhs.SUF+rhs.PREF);
    return vals;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1);

    char oper; 
    int l, r;

    while (m--){
        cin >> oper;
        if (oper == 'S'){
            cin >> l >> r;
            update(1, l-1, r);
        }
        else{
            cin >> l >> r;
            cout << query(1, l-1, r-1).SEG << "\n";
        }
    }
}