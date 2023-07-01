#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
#define f first
#define s second
const int inf=1e9;

vector <int> walkGraph[MAXN];
int goal;
int order[MAXN], rtim[MAXN]; //permutation, time to be at each station to use the train
int ans, dist[MAXN];

void bfs(int curNode, int curDist){
    queue <pair <int, int>> q;
    q.push({curNode, curDist});
    for (int i=0;i <MAXN; i++) dist[i] = 1e9;
    dist[curNode] = 0;


    while (!q.empty()){
        pair <int,int> node = q.front(); q.pop();

        for (int nxt : walkGraph[node.f]){
            if (dist[nxt] > node.s+1){
                dist[nxt] = node.s+1;
                q.push({nxt, node.s+1});
            }
        }
    }   
}

struct segTree{
    int L, R, minVal;
}seg[MAXN*4];

void buildTree(int curNode, int left, int right){
    seg[curNode].L = left; seg[curNode].R = right;

    if (left == right){
        seg[curNode].minVal = dist[left]+rtim[left]-1;
    }
    else{
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        seg[curNode].minVal = min(seg[curNode*2].minVal, seg[curNode*2+1].minVal);
    }
}

void update(int curNode, int idx, int newVal){
    int L= seg[curNode].L, R=seg[curNode].R;

    if (L > idx || R < idx) return;

    if (L==R && L==idx){
        seg[curNode].minVal += newVal;
    }
    else{
        update(curNode*2, idx, newVal);
        update(curNode*2+1, idx, newVal);
        seg[curNode].minVal = min(seg[curNode*2].minVal, seg[curNode*2+1].minVal);
    }
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, w, d; cin >> n >> w >> d;

    goal = n;

    for (int i=0; i<w; i++){
        int a, b; cin >> a>> b;
        walkGraph[b].push_back(a);
    }

    for (int i=1; i<=n; i++){
        cin >> order[i];
        rtim[order[i]] = i;
    }

    bfs(n, 0);
    buildTree(1, 0, n);


    

    for (int i=0; i<d; i++){
        int x, y; cin >> x >> y;

        update(1, order[x], rtim[order[y]]-rtim[order[x]]);
        update(1, order[y], rtim[order[x]]-rtim[order[y]]);

        swap(order[x], order[y]);
        swap(rtim[order[x]], rtim[order[y]]);

        cout << seg[1].minVal<< "\n";   
    }


    
    

    

}