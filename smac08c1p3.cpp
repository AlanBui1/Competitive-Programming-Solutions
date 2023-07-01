#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const int inf = INT_MAX;
int n, d;
__int32_t arr[MAXSZ];
struct segTree{
    __int32_t L, R, minVal;
}seg[MAXSZ*4];

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

int minQuery(int curNode, int QL, int QR){
    int L=s.L, R=s.R;

    if (L > QR || R < QL) return inf;

    else if (QL<=L && R <= QR){
        return s.minVal;
    }

    return min(minQuery(curNode*2, QL, QR), minQuery(curNode*2+1, QL, QR));

}

void update(int curNode, int idx, int newVal){
    int L=s.L, R=s.R;

    if (L > idx || R < idx) return;

    else if (L==R && idx == L){
        s.minVal = newVal;
        return;
    }

    update(curNode*2, idx, newVal);
    update(curNode*2+1, idx, newVal);
    s.minVal = min(cl.minVal, cr.minVal);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> d;

    for (int i=0; i<n; i++) cin >> arr[i];
    buildTree(1, 0, n-1);
    for (int i=1; i<n; i++){
    
        arr[i] += minQuery(1, max(0, i-d), i-1);
        update(1, i, arr[i]);
  
    }


    cout << arr[n-1] << "\n";
}