#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const int nax = 1e5+5;
const ll inf = 1e18;
ll dp[nax], ans = inf;

struct node{
    ll L, R, minVal;
}seg[nax*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;
    s.minVal = inf;

    if (left != right){
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
    }
}

void update(int curNode, int idx, ll newVal){
    int L= s.L, R = s.R;

    if(L > idx || R< idx) return;

    if (L == R && L == idx){
        s.minVal = newVal;
    }
    else{
        update(curNode*2, idx, newVal);
        update(curNode*2+1, idx, newVal);
        s.minVal =min(cl.minVal, cr.minVal);
    }
}

ll query(int curNode, int QL, int QR){
    int L = s.L, R = s.R;
    if (L > QR || R < QL){
        return inf;
    }
    if (QL <= L && R <= QR) return s.minVal;

    return min(query(curNode*2, QL, QR), query(curNode*2+1, QL, QR));
}

int32_t main() {
    cin.sync_with_stdio(0); cin.tie(0);

    for (int i=0; i<nax; i++) dp[i] = inf;

    int n, m, j; cin >>n >> m >> j;
    buildTree(1, 0, n+1);

    int p, x;
    for (int i=0; i<m; i++){
        cin >> p >> x;
        dp[p] = x;
    }
    if (j == 0){
        cout << "-1\n";
        return 0;
    }

    dp[0] = 0;
    update(1, 0, 0);
    dp[n+1] = 0;
    for (int i=1; i<=n+1; i++){
        if (dp[i] == inf) continue;
        ll MIN = query(1, max(0, i-j), i-1);

        dp[i] = max(MIN, dp[i]);
        if (i+j > n){
            ans = min(ans, dp[i]);
        }
        update(1, i, dp[i]);
        
    }
    

    if (ans == inf){
        cout << "-1\n";
    }
    else cout << ans << "\n";
  
}