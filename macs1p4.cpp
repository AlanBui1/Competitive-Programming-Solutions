#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>

const int MAXSZ = 2e4+5;
const int MAXN = (1 << 6);
const int INF = 2e9;

int N, M, K, p[MAXSZ], dist[MAXN][MAXSZ];
vector <pii> graph[MAXSZ];

void solve(){
    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<MAXN; k++){
            dist[k][i] = INF;
        }
    }
    priority_queue<pair<int, pair <int,int>>, vector<pair<int, pair <int, int>>>, greater<pair<int, pair <int, int>>>> q;

    q.push({0, {1, 0}});
    dist[1][0]= 0;
    while (!q.empty()){
        auto TOP = q.top(); q.pop();
        int curNode = TOP.second.first, curDist = TOP.first, used = TOP.second.second;

        if (curDist > dist[used][curNode]) continue;

        for (pair <int, int> nxt : graph[curNode]){
            int nxtDist = nxt.second, nxtNode = nxt.first;
            if (nxtDist + curDist < dist[used][nxtNode]){
                dist[used][nxtNode] = nxtDist + curDist;
                q.push({dist[used][nxtNode], {nxtNode, used}});
            }

            int newMask = used, newDist = nxtDist;

            for (int i=0; i<K; i++){
                if (newMask & (1 << i)){
                    continue;
                }


                if (newDist & (1 << p[i])){
                    newDist ^= (1 << p[i]);
                    newMask ^= (1 << i);
                }

            }
            if (newDist + curDist < dist[newMask][nxtNode]){
                    dist[newMask][nxtNode] = newDist + curDist;
                    q.push({dist[newMask][nxtNode], {nxtNode, newMask}});
                }
        }
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i=0; i<K; i++){
        cin >> p[i];
    }

    for (int i=0; i<M; i++){
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    solve();
    int ans = INF;
    for (int i=0; i<(1 << K); i++){
        ans = min(ans, dist[i][N]);
    }

    cout << ans << "\n";
}