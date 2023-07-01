#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=1e5+5;
const ll inf=8589934591;

ll n, q, arr[MAXSZ], x, v, y;
char oper;
struct segTree{
    int L, R;
    ll val;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    seg[curNode].L=left; seg[curNode].R=right;

    if (left==right){
        seg[curNode].val = arr[left];
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        seg[curNode].val = seg[curNode*2].val&seg[curNode*2+1].val;
    }
}   

void update(int curNode, int idx, ll newVal){
    int L=seg[curNode].L, R=seg[curNode].R;

    if (idx > R || idx < L) return;

    if (L==R && L==idx){
        seg[curNode].val = newVal;
    }
    else{
        update(curNode*2, idx, newVal); update(curNode*2+1, idx, newVal);
        seg[curNode].val = seg[curNode*2].val&seg[curNode*2+1].val;
    }
}


ll query(int curNode, int QL, int QR){
    int L=seg[curNode].L, R=seg[curNode].R;

    if (L>QR || R<QL) return (inf);

    if (QL <= L && R <= QR){
        return (seg[curNode].val);
    }
    return (query(curNode*2, QL, QR)&query(curNode*2+1, QL, QR));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> arr[i];
    buildTree(1, 0, n-1);

    while (q--){
        cin >> oper;
        if (oper=='U'){
            cin >> x >> v;
            update(1, x-1, v);
        }
        else{
            cin >> x >> y >> v;
            cout << (v&query(1, x-1, y-1)) << "\n";
        }
    }

}