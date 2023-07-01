#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+6;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

struct node{
    int L, R, val;
}seg[MAXSZ*4];

int arr[MAXSZ];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;
    s.val= 0;
    if (left == right){
        // s.val = 0;
        return;
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        // s.val = max(cl.val, cr.val);
    }
}

int query(int curNode, int want){
    int L=s.L, R=s.R;

    if (L==R){
        return L;
    }
    
    if (cr.val > want){
        return query(curNode*2+1, want);
    }

    else{
        return query(curNode*2, want);
    }
}

void update(int curNode, int idx, int newVal){
    int L=s.L, R=s.R;

    if (L > idx || R< idx)return;

    else if (L==R && R==idx){
        s.val = newVal;
    }
    else{
        update(curNode*2, idx, newVal);
        update(curNode*2+1, idx, newVal);
        s.val = max(cl.val, cr.val);
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    buildTree(1, 0, n-1);

    cout << 0  << " ";
    update(1, 0, arr[0]);
    for (int i=1; i<n; i++){
        cout << i-query(1, arr[i]) << " ";
        update(1, i, arr[i]);
    }
    cout << "\n";

}