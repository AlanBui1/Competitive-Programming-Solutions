#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+7;
const int MAXSZ = 1e6+5;
vector <int> graph[MAXSZ];
int dist[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0; i<MAXSZ; i++){
        dist[i] = inf;
    }

    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    int s, t; cin >> s >> t;
    dist[s] = 0;

    queue <pair <int, int>> q;
    q.push({s, 0});

    while (!q.empty()){
        auto T = q.front(); q.pop();

        if (dist[T.first] < T.second){
            continue;
        }

        for (int nxt : graph[T.first]){
            if (dist[nxt] > T.second + 1){
                dist[nxt] = T.second + 1;
                q.push({nxt, dist[nxt]});
            }
        }
    }

    cout << m - dist[t] << "\n";


}