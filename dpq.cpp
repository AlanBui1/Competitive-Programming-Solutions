#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
#define ll long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const ll inf = 1e18;

ll n, h[MAXSZ], a[MAXSZ], dp[MAXSZ];

struct segTree{
    int L, R;
    ll maxVal;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L=left; s.R=right;
    s.maxVal = 0;

    if (left!=right){
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
    }
}   

ll maxQuery(int curNode, int QL, int QR){
    int L=s.L, R=s.R;

    if (L>QR || R<QL) return 0;

    else if (QL <= L and R <= QR){
        return s.maxVal;
    }
    return max(maxQuery(curNode*2, QL, QR), maxQuery(curNode*2+1, QL, QR));
}

void update(int curNode, int idx, ll newVal){
    int L=s.L, R=s.R; 

    if (L > idx || R < idx)return;

    else if (L==R and L==idx){
        s.maxVal = newVal;
    }

    else{
        update(curNode*2, idx, newVal);
        update(curNode*2+1, idx, newVal);
        s.maxVal = max(cl.maxVal, cr.maxVal);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> h[i];
    for (int i=0; i<n; i++) cin >> a[i];

    buildTree(1, 0, MAXSZ+1);

    ll ans =0;

    for (int i=0; i<n; i++){
   
        dp[i+1] = max(a[i], a[i]+maxQuery(1,0,h[i]));
       
        update(1, h[i], dp[i+1]);

        ans = max(ans, dp[i+1]);
    }

    cout << ans << "\n";

}