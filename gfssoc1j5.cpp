#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1005;
const int inf = 1e9;

vector <int> graph[MAXSZ];
int dist[MAXSZ][MAXSZ];
bool visited[MAXSZ];

void bfs(int s){
    dist[s][s] = 0;
    for (int i=0; i<MAXSZ; i++){
        visited[i] = false;
    }
    queue <int> q;
    q.push(s);

    while (!q.empty()){
        int curNode = q.front(); q.pop();
        for (int nxt : graph[curNode]){
            if (!visited[nxt]){
                visited[nxt] = true;
                dist[s][nxt] = dist[s][curNode]+1;
                q.push(nxt);
            }
        }
    }
}


int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m, t; cin >> n >> m >> t;

    for (int i=0; i<m; i++){
        int a, b;
        cin >> a>> b;
        graph[a].push_back(b);
    }

    int q; cin >> q;
    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<MAXSZ;k++){
            dist[i][k] = inf;
        }
    }

    for (int i=1; i<=n; i++){
        bfs(i);
    }

    for (int i=0; i<q; i++){
        int x, y; cin >> x>> y;
        if (dist[x][y] == inf){
            cout << "Not enough hallways!" << "\n";
        }
        else{
            cout << dist[x][y]*t << "\n";
        }
    }


}