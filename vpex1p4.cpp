#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXSZ=1e5+5;
#define pii pair <ll, ll>
#define f first
#define se second
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const ll inf = 1e18;

vector <pii> graph[MAXSZ];
vector <ll> euler;

struct node{
    int L, R, spot;
}seg[MAXSZ*8];

ll height[MAXSZ], first[MAXSZ];

bitset <MAXSZ> visited;

void dfs(ll curNode, ll prevNode, ll H){
    visited[curNode]= 1;
    first[curNode] = euler.size();
    height[curNode] = H;
    euler.push_back(curNode);

    for (pii nxt : graph[curNode]){
        if (!visited[nxt.f] && prevNode != nxt.f){
            dfs(nxt.f, curNode, H+nxt.se);
            euler.push_back(curNode);
        }
    }
}

void buildTree(ll curNode, ll left, ll right){
    s.L = left; s.R = right;

    if (left == right){
        s.spot = euler[left];
        return;
    }
    ll mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
    s.spot = height[cl.spot] < height[cr.spot] ? cl.spot : cr.spot;
}

ll query(ll curNode, ll QL, ll QR){
    ll L = s.L, R = s.R;
    if (L > QR || R < QL) return inf;
    if (QL <= L && R <= QR) return height[s.spot];
    return min(query(curNode*2, QL, QR), query(curNode*2+1, QL, QR));
}

ll LCA(ll u, ll v){
    ll left = first[u], right = first[v];
    if (left > right) swap(left, right);
    return query(1, left, right);
}

ll DIST(ll u, ll v){
    return height[u]+height[v]-(2*LCA(u, v));
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    ll n, d, a, b, x, y,z, u, v;
    cin >> n >> d;

    for (ll i=0; i<n-1; i++){
        cin >> u >> v >> z;
        graph[u].push_back({v, z});
        graph[v].push_back({u, z});
    }

    dfs(1,1,0);

    buildTree(1, 0, euler.size()-1);

    ll start1 = 1,start2 = 1, op1 = inf, op2 = inf, prev1 = 0, prev2 = 0;

    while (d--){
        cin >> a >> b;
        op1 = inf; op2 = inf;

        op1 = min(op1,DIST(start1, b)+prev1);
        op1 = min(op1, DIST(start2, b)+prev2);
        op1 += DIST(b, a);
        op2 = min(op2, DIST(start1, a)+prev1);
        op2 = min(op2, DIST(start2, a)+prev2);
        op2 += DIST(a, b);

        start1 = a;
        start2 = b;
        prev1 = op1;
        prev2 = op2;
    }

    cout << min(op1, op2) << "\n";

}