#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=5e4+5;
#define inf INT_MAX
int n, q, arr[MAXSZ], l, r;

struct segTree{
    int L, R;
    int minVal, maxVal;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    seg[curNode].L=left; seg[curNode].R=right;

    if (left==right){
        seg[curNode].minVal = arr[left];
        seg[curNode].maxVal = arr[left];
    }

    else{
        int mid=(left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);

        seg[curNode].minVal = min(seg[curNode*2].minVal, seg[curNode*2+1].minVal);
        seg[curNode].maxVal = max(seg[curNode*2].maxVal, seg[curNode*2+1].maxVal);
    }
}

int maxQuery(int curNode, int QL, int QR){
    int L=seg[curNode].L, R=seg[curNode].R;

    if (L>QR || R<QL){
        return -1;
    }

    if (QL <= L && R <= QR){
        return seg[curNode].maxVal;
    }

    return max(maxQuery(curNode*2, QL, QR), maxQuery(curNode*2+1, QL, QR));
}

int minQuery(int curNode, int QL, int QR){
    int L=seg[curNode].L, R=seg[curNode].R;

    if (L>QR || R<QL){
        return inf;
    }

    if (QL <= L && R <= QR){
        return seg[curNode].minVal;
    }

    return min(minQuery(curNode*2, QL, QR), minQuery(curNode*2+1, QL, QR));
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i=0; i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1);
    
    while (q--){
        cin >> l >> r;
        l--; r--;
        cout << maxQuery(1, l, r) - minQuery(1, l, r) << "\n";
    }
}