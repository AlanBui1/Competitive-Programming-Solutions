#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define ll long long
#define inf LLONG_MAX

const int MAXSZ=1e5+5;

int n, q, l, r, v, oper, arr[MAXSZ];

struct segTree{

    int L, R;
    ll minVal, lazyInc, lazyModify;

}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    seg[curNode].L=left; seg[curNode].R=right;
    seg[curNode].lazyInc=0; seg[curNode].lazyModify=0;
    if (left==right){
        seg[curNode].minVal = arr[left];
    }
    else{
        int mid = (left+right)/2;

        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        seg[curNode].minVal= min(seg[curNode*2].minVal, seg[curNode*2+1].minVal);
    }
}

void lazyPush(int curNode){
    int L = seg[curNode].L, R=seg[curNode].R;
    if (seg[curNode].lazyModify > 0){
        if (L==R){
            seg[curNode].minVal = seg[curNode].lazyModify;
            seg[curNode].lazyModify = 0;
            return;
        }
        seg[curNode].minVal = seg[curNode].lazyModify;
        seg[curNode*2].lazyModify =  seg[curNode].lazyModify;
        seg[curNode*2].lazyInc = 0;
        seg[curNode*2+1].lazyModify =  seg[curNode].lazyModify;
        seg[curNode*2+1].lazyInc = 0;
        seg[curNode].lazyModify = 0;
    } 
    if (seg[curNode].lazyInc > 0){
        if (L==R){
  
            seg[curNode].minVal += seg[curNode].lazyInc;
            seg[curNode].lazyInc = 0;
            return;
        }
        seg[curNode].minVal = seg[curNode].minVal + seg[curNode].lazyInc;
        seg[curNode*2].lazyInc += seg[curNode].lazyInc;
        seg[curNode*2+1].lazyInc += seg[curNode].lazyInc;
        seg[curNode].lazyInc = 0;
    }

       
}


void modifyUpdate(int curNode, int UL, int UR, int newVal){
    int L = seg[curNode].L, R=seg[curNode].R;

    while (seg[curNode].lazyModify>0 || seg[curNode].lazyInc > 0) lazyPush(curNode);

    //Case 1: completely out
    if (L>UR || R<UL) return;

    //Case 2: completely in
    if (UL <= L && R <= UR){
        seg[curNode].lazyModify = newVal;
        seg[curNode].lazyInc = 0;
        lazyPush(curNode);
        return;
    }

    //Case 3: partially in
    modifyUpdate(curNode*2, UL, UR, newVal);
    modifyUpdate(curNode*2+1, UL, UR, newVal);
    seg[curNode].minVal = min(seg[curNode*2].minVal, seg[curNode*2+1].minVal);
}

void incUpdate(int curNode, int UL, int UR, int newVal){
    int L = seg[curNode].L, R=seg[curNode].R;

    while (seg[curNode].lazyModify>0 || seg[curNode].lazyInc > 0) lazyPush(curNode);

    //Case 1: completely out
    if (L>UR || R<UL) return;

    //Case 2: completely in
    if (UL <= L && R <= UR){
        if (seg[curNode].lazyModify > 0){
            seg[curNode].lazyModify += newVal;
        }
        else{
            seg[curNode].lazyInc += newVal;

        }
        lazyPush(curNode);
        return;
    }

    //Case 3: partially in
    incUpdate(curNode*2, UL, UR, newVal);
    incUpdate(curNode*2+1, UL, UR, newVal);
    seg[curNode].minVal = min(seg[curNode*2].minVal, seg[curNode*2+1].minVal);
}

ll minQuery(int curNode, int QL, int QR){
    int L = seg[curNode].L, R=seg[curNode].R;
    
    //DO SOMETHING WITH LAZY HERE
    //LAZY PUSH SOMEHOW

    while (seg[curNode].lazyInc > 0 || seg[curNode].lazyModify > 0){
        lazyPush(curNode);
    }


    // completely out
    if (L>QR || R<QL) return inf;
    //completely in
    if (QL<= L && R<=QR) return seg[curNode].minVal;
    //partially in 
    return min(minQuery(curNode*2, QL, QR), minQuery(curNode*2+1, QL, QR));
}

int main() {
    scan(n); scan(q);
    
    for (int i=0; i<n; i++) scan(arr[i]);

    buildTree(1, 0, n-1);

    while (q--){
        scan(oper);
        if (oper==1){
            scan(l); scan(r); scan(v);
            l--; 
            r--;        
            incUpdate(1, l, r, v);
        }

        else if (oper==2){
            scan(l); scan(r); scan(v);
            l--; 
            r--;
            modifyUpdate(1, l, r, v);
        }

        else{
            scan(l); scan(r);
            l--; r--;
            cout << minQuery(1, l, r) << "\n";
        }
    }
}