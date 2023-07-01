#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=1e5+5;
const ll inf = 1e18;


struct edge{
    int b, d, pass; //nxtNode, dist, pass #
};

vector <edge> graph[MAXSZ];
int n, m, a, b, c;

ll dist[MAXSZ];

bool dijkstra(int s, int e, int p){

    for (int i=0; i<MAXSZ; i++) dist[i] = inf;

    priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;

    pq.push({0, s});
    dist[s] = 0;
    pair <int, int> node; int curNode, curDist;
    while (!pq.empty()){
        node = pq.top(); pq.pop();
        curNode = node.second; curDist = node.first;

        if (dist[curNode] < curDist) continue;

        if (dist[e] < c) return true;

        for (edge nxt : graph[curNode]){
            if (nxt.pass > p) continue;
            if (dist[nxt.b] > curDist+nxt.d){
                dist[nxt.b] = curDist+nxt.d;
                pq.push({dist[nxt.b], nxt.b});
            }
        }
    }

    return dist[e] < c;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 

    cin >> n >> m;
    int x, y, z;
    for (int i=0; i<m; i++){
        cin >> x >> y >> z;
        graph[x].push_back({y, z, i+1});
        graph[y].push_back({x, z, i+1});
    }
    //dijkstras +bsearch on level of pass
    int L=1, R=m, ans=1e9;
    cin >> a >> b >> c;
    while (L <= R){
        int mid = (L+R)/2;

        if (dijkstra(a, b, mid)){
            ans = min(ans, mid);
            R = mid-1;
        }
        else{
            L = mid+1;
        }
    }
    if (ans == 1e9) cout << "-1\n";
    else cout << ans << "\n";
}