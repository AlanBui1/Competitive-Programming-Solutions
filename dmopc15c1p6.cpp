#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAXSZ=2e5+5;
int n, m, q, oper, l, r, x, arr[MAXSZ];

struct segTree{
    int L, R, val, lazy;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    seg[curNode].L=left; seg[curNode].R=right; 
    seg[curNode].lazy=0;

    if (left == right) seg[curNode].val=arr[left];

    else{
        int mid=(left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        seg[curNode].val=seg[curNode*2].val%m+seg[curNode*2+1].val%m;
    }
}

void lazyPush(int v){
    int L=seg[v].L, R=seg[v].R;

    seg[v].val += (seg[v].lazy)*(R-L+1);
    seg[v].val %=m;
    
    if (L==R){
        seg[v].lazy=0;
        return;
    }

    seg[v*2].lazy+=seg[v].lazy;
    seg[v*2+1].lazy+=seg[v].lazy;
    seg[v*2].lazy %=m;
    seg[v*2+1].lazy %=m;
    seg[v].lazy=0;
}

int sumQuery(int curNode, int QL, int QR){
    int L=seg[curNode].L, R=seg[curNode].R;

    if (seg[curNode].lazy>0) lazyPush(curNode);

    if (L>QR || R<QL) return 0;
    if (QL <= L && R <= QR) return seg[curNode].val%m;

    return (sumQuery(curNode*2, QL, QR)%m)+(sumQuery(curNode*2+1, QL, QR)%m);

}

void update(int curNode, int UL, int UR ,int newVal){
    int L=seg[curNode].L, R=seg[curNode].R;
    if (seg[curNode].lazy>0) lazyPush(curNode);

    if (L>UR || R <UL) return;

    if (UL <= L && R <= UR){
        seg[curNode].lazy+=newVal;
        seg[curNode].lazy %= m;
        lazyPush(curNode);
        return;
    }
    
    update(curNode*2, UL, UR, newVal);
    update(curNode*2+1, UL, UR, newVal);
    seg[curNode].val=seg[curNode*2].val%m+seg[curNode*2+1].val%m;
}

int main() {
    scan(m); scan(n); scan(q);
    for (int i=0; i<n; i++) scan(arr[i]);
    buildTree(1, 0, n-1);

    while (q--){
        scan(oper);
        if (oper==1){ //update
            scan(l); scan(r); scan(x);
            l--; r--;
            update(1, l, r, x);
        }

        else{ //query
            scan(l); scan(r);
            l--; r--;
            cout << sumQuery(1, l, r)%m << "\n";
            // for (int i=1; i<10; i++) cout << seg[i].val << " ";
            // cout << "\n";
            // for (int i=1; i<10; i++) cout << seg[i].lazy << " ";
            // cout << "\n";
        }
    }
}