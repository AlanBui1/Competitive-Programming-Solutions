#include <bits/stdc++.h>
using namespace std;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

const int MAXSZ=1e6+5;
const int inf =1e9;

char arr[MAXSZ];
int n;
long long ans=0;

struct node{
    int L, R, cnt;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L= left; s.R=right;

    if (left == right){
        if (arr[left] == '1') s.cnt = 1;
        else s.cnt = 0;
        return;
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        s.cnt = cl.cnt+cr.cnt;
    }

}

int lo(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (R < QL || L > QR || s.cnt <= 0) return inf;

    if (L == R){
        if (s.cnt > 0) return L;
        else return inf;
    }

    if (QL <= L && R <= QR){
        if (cl.cnt > 0){
            return lo(curNode*2, QL, QR);
        }
        return lo(curNode*2+1, QL, QR);
    }

    return min(lo(curNode*2, QL, QR), lo(curNode*2+1, QL, QR));
}

int hi(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL || s.cnt <= 0) return -1;

    if (L == R){
        if (s.cnt > 0) return L;
        else return -1;
    }

    if (QL <= L && R <= QR){
        if (cr.cnt > 0) return hi(curNode*2+1, QL, QR);
        else return hi(curNode*2, QL, QR);
    }
    return max(hi(curNode*2, QL, QR), hi(curNode*2+1, QL, QR));
}


int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    buildTree(1, 0, n-1);

    for (int i=0; i<n; i++){
        if (arr[i] == '1'){
            continue;
        }

        int op1 = hi(1, 0, i), op2 = lo(1, i, n-1);

        if (op1 == -1) op2 = inf;

        ans += min(abs(i-op1), abs(i-op2));

    }

    cout << ans << "\n";

}