#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9+7;
const int MAXSZ = 1e5+5;

vector <int> graph[MAXSZ];
int n, m, q, k, dist[MAXSZ];

int day(int v){
    int curDay = 0;

    while ((curDay)*(curDay+1)/2*k < v){
        curDay++;
    }
    return curDay;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q >> k;
    queue <pair <int, int>> qu;

    for (int i=0; i<MAXSZ; i++){
        dist[i] = INF;
    }

    for (int i=0; i<q; i++){
        int x; cin >> x;
        qu.push({x, 0});
        dist[x] = 0;
    }
    for (int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    while (!qu.empty()){
        auto TOP = qu.front(); qu.pop();
        int curNode = TOP.first, curDist = TOP.second;

        if (dist[curNode] < curDist) continue;

        for (int nxt : graph[curNode]){
            if (dist[nxt] > curDist + 1){
                dist[nxt] = curDist + 1;
                qu.push({nxt, dist[nxt]});
            }
        }

    }

    for (int i=1; i<=n; i++){
        cout << day(dist[i]) << " ";
    }

}