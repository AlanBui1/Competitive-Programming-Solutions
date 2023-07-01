#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e3+5;
const int MAXV = 1e5+5;

#define int long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

vector <int> graph[MAXSZ], euler, allVals[MAXSZ];
int height[MAXSZ], first[MAXSZ], vals[MAXSZ], freq[MAXV];
bool visited[MAXSZ];

struct segTree{
    int L, R, minHeight, node;
}seg[MAXV];

void buildTree(int curNode, int left, int right){
    s.L= left;
    s.R = right;

    if (left == right){
        s.minHeight = height[euler[left]];
        s.node = euler[left];
        return;
    }

    int mid = (left+right)/2;

    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);

    if (cl.minHeight < cr.minHeight){
        s.minHeight = cl.minHeight;
        s.node = cl.node;
    }
    else{
        s.minHeight = cr.minHeight;
        s.node = cr.node;
    }
}

segTree query(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR || R < QL){
        segTree ret; ret.minHeight = 1000000; ret.node = -1;
        return ret;
    }

    if (QL <= L && R <= QR){
        return s;
    }

    segTree lhs = query(curNode*2, QL, QR), rhs = query(curNode*2+1, QL, QR);

    if (lhs.minHeight < rhs.minHeight){
        return lhs;
    }
    return rhs;
}

void dfs(int curNode, int prevNode, int H){
    visited[curNode] = 1;
    height[curNode] = H;

    first[curNode] = euler.size();

    euler.push_back(curNode);
    for (int v : allVals[prevNode]){
        allVals[curNode].push_back(v);
    }
    allVals[curNode].push_back(vals[curNode]);

    for (int nxtNode : graph[curNode]){
        if (prevNode == nxtNode) continue;
        if (visited[nxtNode]) continue;
        dfs(nxtNode, curNode, H+1);
        euler.push_back(curNode);
    }
}

int LCA(int u, int v){
    int left = first[u], right = first[v];
    if (left > right){
        swap(left, right);
    }
    return query(1, left, right).node;
}

int numNodes(){
    int ret = 0;
    for (int i=0; i<MAXV; i++) ret+=freq[i];
    return ret;
}

int round(int x, int y){ //rounds x/y
    int ret = x/y;
    if (x%y < y/2 + (y%2 > 0)) return ret;
    return ret+1;
}

int findElement(int ind){
    for (int i=0; i<MAXV; i++){
        ind -= freq[i];
        if (ind <= 0){
            return i;
        }
    }
    return -1;
}

int mean(){
    int sum = 0;
    for (int i=0; i<MAXV; i++) sum += freq[i]*i;
    return round(sum, numNodes());
}

int mode(){
    int ret = 0, cnt = 0;
    for (int i=0; i<MAXV; i++){
        if (freq[i] > cnt){
            ret = i;
            cnt = freq[i];
        }
    }
    return ret;
}

int median(){
    int N = numNodes();

    if (N % 2 == 1){
        return findElement(N/2 +1);
    }
    int med = findElement(N/2) + findElement(N/2 +1);
    //cout << "MED " << med << "\n";
    return round(med, 2);
}

signed main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> vals[i];
    }

    for (int i=0; i<n-1; i++){
        int a, b; cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, 0, 0);
    int m = euler.size() -1;
    buildTree(1, 0, m);

    while (q--){
        int op, x, y; cin >> op >> x >> y; x--; y--;
        int lca = LCA(x, y);

        for (int i=0; i<MAXV; i++) freq[i] = 0;

        for (int i : allVals[x]){
            freq[i]++;
        }
        for (int i : allVals[y]){
            freq[i]++;
        }
        for (int i : allVals[lca]){
            freq[i]--;
        }
        for (int i : allVals[lca]){
            freq[i]--;
        }
        freq[vals[lca]]++;
        //cout << lca << " " << numNodes() << " ";
        if (op == 1){
            cout << mean() << "\n";
        }
        else if (op == 2){
            cout << median() << "\n";
        }
        else{
            cout << mode() << "\n";
        }


    }
}