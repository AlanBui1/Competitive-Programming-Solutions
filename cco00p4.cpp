#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
const int MAXSZ = 200;
const int INF = 2e9;

int n, w, p, height[MAXSZ], val[MAXSZ], first[MAXSZ];
vector <pii> graph[MAXSZ];
vector <int> euler;

void dfs(int curNode, int prevNode, int curHeight, int curVal){
    height[curNode] = curHeight;
    val[curNode] = curVal;
    first[curNode] = euler.size();
    euler.push_back(curNode);

    for (pii nxt : graph[curNode]){
        if (prevNode == nxt.first) continue;
        dfs(nxt.first, curNode, curHeight+1, curVal+nxt.second);
        euler.push_back(curNode);
    }
}

struct node{
    int L, R, ind;
}seg[MAXSZ*8];

void buildTree(int curNode, int left, int right){
    seg[curNode].L = left; seg[curNode].R = right;

    if (left == right){
        seg[curNode].ind = euler[left];
        return;
    }

    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);

    seg[curNode].ind = height[seg[curNode*2].ind] < height[seg[curNode*2+1].ind] ? seg[curNode*2].ind : seg[curNode*2+1].ind;

}

int query(int curNode, int QL, int QR){
    int L = seg[curNode].L, R = seg[curNode].R;

    if (L > QR || R < QL){
        return MAXSZ-1;
    }

    if (QL <= L && R <= QR){
        return seg[curNode].ind;
    }

    int LHS = query(curNode*2, QL, QR), RHS = query(curNode*2+1, QL, QR);

    return height[LHS] < height[RHS] ? LHS : RHS;
}

int lca(int u, int v){
    int left = first[u], right = first[v];
    if (left > right) swap(left, right);

    return query(1, left, right);
}



int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    height[MAXSZ-1] = INF;
    cin >> n >> w >> p;

    for (int i=0; i<w; i++){
        int a, b,c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs(1, 1, 0, 0);
    buildTree(1, 0, euler.size()-1);

    while (p--){
        int u, v; cin >> u >> v;
        int LCA = lca(u, v);
        //cout << LCA << "\n";
        //assert(n < 0);

        cout << val[u] + val[v] - 2*val[LCA] << "\n";
    }

}