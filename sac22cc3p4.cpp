#include <bits/stdc++.h>
using namespace std;
const int nax = 2e5+5;
const int inf = 1e9;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

int parent[nax], siz[nax], height[nax], first[nax];
vector <int> graph[nax], start[nax], euler;
bitset <nax> visited;

void preprocess(int curNode, int prevNode, int H){
    height[curNode] = H;
    first[curNode] = euler.size();
    euler.push_back(curNode);
    visited[curNode] = 1;

    for (int nxt : graph[curNode]){
        if (prevNode == nxt || visited[nxt]) continue;
        preprocess(nxt, curNode, H+1);
        euler.push_back(curNode);
    }

}

int find(int a){
    return a == parent[a] ? a : parent[a] =find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a != b){
        if (siz[a] > siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }

}

struct query{
    int oper, u, v;
};

struct segTree{
    int L, R, spot;
}seg[nax*8];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;

    if (left == right){
        s.spot = euler[left];
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        s.spot = height[cl.spot] < height[cr.spot] ? cl.spot : cr.spot;
    }
}

int minq(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL ) return inf;
    if (QL <= L && R <= QR) return height[s.spot];
    return min(minq(curNode*2, QL, QR), minq(curNode*2+1, QL, QR));
}

int dist(int u, int v){
    int left = first[u], right = first[v];
    if (left > right) swap(left, right);
    return height[u]+height[v] - (2*minq(1, left, right));
}

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int n, q; cin >> n >> q;

    for (int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
        start[a].push_back(b);
        start[b].push_back(a);
    }

    stack <query> st;
    for (int i=0; i<q; i++){
        int op, u, v; cin >> op >> u >> v;
        query Q; Q.oper = op; Q.u = u; Q.v = v;
        st.push(Q);

        if (op == 2){
            start[u].erase(find(start[u].begin(), start[u].end(), v));
            start[v].erase(find(start[v].begin(), start[v].end(), u));
        }
    }
    for (int i=0; i<nax; i++){
        siz[i] = 1; parent[i] = i;
    }

    for (int i=1; i<=n; i++){
        for (int k : start[i]) unionsets(i, k);
    }

    preprocess(1, 1, 0);

    buildTree(1, 0, euler.size()-1);

    stack <int> ans;

    while (!st.empty()){
        query Q = st.top(); st.pop();

        if (Q.oper == 1){
            if (find(Q.u) != find(Q.v)){
                ans.push(-1);
            }
            else{
                ans.push(dist(Q.u, Q.v));
            }
        }
        else{
            unionsets(Q.u, Q.v);
        }
    }

    while (!ans.empty()){
        cout << ans.top() << "\n"; ans.pop();
    }

}