#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 25;
const int inf = 1e9+7;

int n, m, dist[MAXSZ], cycle = 0;
vector <int> graph[MAXSZ];

void dfs(int curNode, int curDist){
    //cout << curNode << " " << curDist << "\n";
    for (int nxtNode : graph[curNode]){
        if (dist[nxtNode] == inf){
            dist[nxtNode] = curDist+1;
            dfs(nxtNode, curDist+1);
            dist[nxtNode] = inf;
        }
        else{
           // cout << "CYCLE " <<curNode << " " << nxtNode << " " << curDist<< "\n";
            cycle = max(cycle, curDist + 1 - dist[nxtNode]);
        }
    }
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for (int i=1; i<=n; i++){
        for (int k=0; k<MAXSZ; k++){
            dist[k] = inf;
        }
        dist[i] = 0;
        dfs(i, 0);
    }

    //cout << cycle;

    if (cycle >= 6){
        cout << "YES\n";
    }
    else cout << "NO\n";
}