#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX;

const int MAXSZ = 1e5+5;
int n, m;
int arr[MAXSZ];
struct Node{
    int L, R;
    int val;

}seg[MAXSZ*3];

void buildTree(int left, int right, int v){
    seg[v].L = left; seg[v].R = right;

    if (left == right){
        seg[v].val = arr[left];
    }

    else{
        int mid = (left+right)/2;
        buildTree(left, mid, v*2);
        buildTree(mid+1, right, v*2 +1);
        seg[v].val = min(seg[v*2].val, seg[v*2+1].val);
    }

}

void update(int curNode, int idx, int newVal){  
    int L=seg[curNode].L, R=seg[curNode].R;

    if (idx < L || idx > R) return;
    if (L==R && L==idx){
        seg[curNode].val = newVal;
    }
    else if (L <= idx && idx <= R){
        update(curNode*2, idx, newVal);
        update(curNode*2+1, idx, newVal);
        seg[curNode].val = min(seg[curNode*2].val, seg[curNode*2+1].val);
    }
}

int query(int curNode, int Q_l, int Q_r){
    int L=seg[curNode].L, R=seg[curNode].R;

    if (Q_r < L || R < Q_l){
        return inf;
    }

    if (Q_l <= L && R <= Q_r){
        return seg[curNode].val;
    }

    return min(query(curNode*2, Q_l, Q_r), query(curNode*2+1, Q_l, Q_r));

}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    buildTree(0, n-1, 1);
    char oper;
    int newVal, QL, QR, idx;

    while (m--){
        cin >> oper;
        if (oper == 'M'){
            cin >> idx >> newVal;
            update(1, idx, newVal);
        }

        else{
            cin >> QL >> QR;
            cout << query(1, QL, QR) << "\n";
        }
    }
}