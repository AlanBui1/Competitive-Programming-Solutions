#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 30005;
const int INF = 2e9;

int dist[MAXSZ];
vector <int> graph[MAXSZ];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;

    for (int i=0; i<MAXSZ; i++){
        dist[i] = INF;
    }

    for (int i=0; i<M; i++){
        int a, b; cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue <pair <int, int>> q;

    int K; cin >> K;
    for (int i=0;i<K; i++){
        int x; cin >> x;
        dist[x] = 0;

        q.push({x, 0});
    }

    while (!q.empty()){
        pair <int, int> info = q.front(); q.pop();
        int curNode = info.first, curDist = info.second;

        if (curDist > dist[curNode]) continue;

        for (int nxt : graph[curNode]){
            if (curDist + 1 < dist[nxt]){
                dist[nxt] = curDist + 1;
                q.push({nxt, dist[nxt]});
            }
        }
    }
    int ans = 0;
    for (int i=1; i<=N; i++){
        ans = max(ans, dist[i]);
    }

    cout << ans << "\n";
}