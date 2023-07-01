#include <bits/stdc++.h>
using namespace std;

int dist[105][105];
int n, k;

vector <int> graph[105];

int dfs(int curNode, int curDist){
    if (curDist == 0){
        dist[curNode][curDist] = 1;
        return 1;
    }

    if (dist[curNode][curDist] != -1){
        return dist[curNode][curDist];
    }
    int ret =0 ;
    for (int nxt : graph[curNode]){
        ret += dfs(nxt, curDist-1);
    }

    dist[curNode][curDist] = ret;
    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >>n >> k;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            int x; cin >> x;
            if (x){
                graph[i].push_back(j);
            }
        }
    }

    memset(dist, -1, sizeof(dist));

    for (int i=1; i<=n; i++){
        dfs(i, k);
    }

    int ans =0 ;
    for (int i=1; i<=n; i++){
        ans += dist[i][k];
    }

    cout << ans << "\n";
    
}