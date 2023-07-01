#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;
const int inf = 2e9;
#define ll long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

struct node{
    int L, R;
    ll cost, ind;
}seg[MAXSZ*4];

ll scores[MAXSZ], costToUse[MAXSZ];
ll n, m, k;

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        if (scores[left] < m) s.cost = costToUse[left];
        else s.cost = inf;
        s.ind = left;
        return;
    }

    int mid  = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);

    if (cl.cost < cr.cost){
        s.cost = cl.cost;
        s.ind = cl.ind;
    }
    else{
        s.cost = cr.cost;
        s.ind = cr.ind;
    }
}

void update(int curNode, int idx, int val){
    int L = s.L, R = s.R;

    if (L == R && L == idx){
        s.cost = val;
        return;
    }

    if (L > idx || R < idx) return;
    update(curNode*2, idx, val);
    update(curNode*2+1, idx, val);

    if (cl.cost < cr.cost){
        s.cost = cl.cost;
        s.ind = cl.ind;
    }
    else{
        s.cost = cr.cost;
        s.ind = cr.ind;
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;
    ll tot= 0, ans = 0;

    for (int i=0; i<n; i++){
        cin >> scores[i] >> costToUse[i];
        tot += scores[i];
    }

    buildTree(1, 0, n-1);

    ll want = n*k-tot;

    while (want > 0){
        ll times = min(want, m-scores[seg[1].ind]);
        ans += seg[1].cost*times;
        update(1, seg[1].ind, inf);
        want -= times;

    }
    cout << ans << "\n";
}