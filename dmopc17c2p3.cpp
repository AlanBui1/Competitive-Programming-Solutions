#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 2e5+5;
const int INF = 1e9+7;

int N, R, dist[MAXSZ], height[MAXSZ], first[MAXSZ], parent[MAXSZ];
vector <int> graph[MAXSZ], euler;

void dfs(int curNode, int prevNode, int h){
    parent[curNode] = prevNode;
    height[curNode] = h;
    first[curNode] = euler.size();
    euler.push_back(curNode);

    for (int nxt : graph[curNode]){
        if (nxt != prevNode){
            dfs(nxt, curNode, h+1);
            euler.push_back(curNode);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    for (int i=0; i<MAXSZ; i++){
        dist[i] = INF;
    }

    cin >> N >> R;
    for (int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue <pair <int, int>> q;

    for (int i=0; i<R; i++){
        int r; cin >> r;
        dist[r] = 0;
        q.push({r, 0});
    }

    while (!q.empty()){
        auto TOP = q.front(); q.pop();
        int curNode = TOP.first, curDist = TOP.second;

        if (dist[curNode] < curDist) continue;

        for (int nxt : graph[curNode]){
            if (dist[nxt] > curDist+1){
                dist[nxt] = curDist+1;
                q.push({nxt, dist[nxt]});
            }
        }
    }

    int x, y; cin >> x >> y;
    dfs(1, 1, 0);

    int left = first[x], right = first[y];
    if (left > right)
        swap(left, right);
    height[0] = INF;
    int lca = 0;

    for (int i=left; i<=right; i++){
        lca = height[lca] < height[euler[i]] ? lca : euler[i];
    }
    //cout << lca << "\n";
    int ans = INF;
    while (true){
        ans = min(ans, dist[x]);
        if (x == lca){
            break;
        }
        x = parent[x];
    }
    while (true){
        ans = min(ans, dist[y]);
        if (y == lca){
            break;
        }
        y = parent[y];
    }
    cout << ans << "\n";
}