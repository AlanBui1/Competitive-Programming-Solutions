#include <bits/stdc++.h>
using namespace std;

#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

const int MAXSZ = 1e5+5;

struct node{
    int L, R, val, lazy;
}seg[MAXSZ*4];

void lazyPush(int curNode){
    int L = s.L, R = s.R;
    s.val += s.lazy*(R - L + 1);

    if (L == R){
        s.lazy = 0;
    }
    else{
        cl.lazy += s.lazy;
        cr.lazy += s.lazy;
        s.lazy = 0;
    }
}

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right; s.lazy = 0; s.val = 0;

    if (left == right){
        return;
    }
    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
}

int query(int curNode, int QL, int QR){
    int L = s.L, R = s.R;
    if (s.lazy > 0) lazyPush(curNode);
    if (L > QR || R < QL) return 0;
    if (QL <= L && R <= QR) return s.val;
    return query(curNode*2, QL, QR) + query(curNode*2+1, QL, QR);
}

void update(int curNode, int UL, int UR){
    int L = s.L, R = s.R;
    if (s.lazy > 0) lazyPush(curNode);

    if (L > UR || R < UL) return;
    if (UL <= L && R <= UR){
        s.lazy++;
    }
    else{
        update(curNode*2, UL, UR);
        update(curNode*2+1, UL, UR);
    }
}

void reduce(int curNode, int idx, int v){
    int L = s.L, R = s.R;

    if (s.lazy > 0) lazyPush(curNode);
    if (L > idx || R < idx) return;
    if (L == R && L == idx){
        s.val -= v;
        return;
    }
    reduce(curNode*2, idx, v);
    reduce(curNode*2+1, idx, v);

    s.val = cl.val + cr.val;
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    buildTree(1, 0, MAXSZ);

    int N; cin >> N;
    for (int i=0; i<N; i++){
        int left, right; cin>>left >> right;
        cout << query(1, left, left) + query(1, right, right) << "\n";
        reduce(1, left, query(1, left, left));
        reduce(1, right, query(1, right, right));
        update(1, left+1, right-1);
    }
}