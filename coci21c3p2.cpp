#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;

int N, M, highestDist, bestNode;
vector <int> graph[MAXSZ];
bool vis[MAXSZ];

void dfs(int curNode, int prevNode, int dist){
    vis[curNode] = 1;
    if (dist > highestDist){
        highestDist = dist;
        bestNode = curNode;
    }

    for (int nxt : graph[curNode]){
        if (nxt != prevNode){
            dfs(nxt, curNode, dist+1);
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;

    for (int i=1; i<=N; i++){
        if (vis[i]) continue;

        highestDist = 0;
        bestNode = 0;

        dfs(i, i, 1);
        dfs(bestNode, bestNode, 1);
        ans += highestDist;
    }
    cout << ans << "\n";

}