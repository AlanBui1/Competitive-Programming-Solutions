#include <bits/stdc++.h>
using namespace std;

const int nax = 1005;
const int inf = 1e9;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define pii pair <int, int>
#define f first
#define s second

vector <pii> graph[nax];
bitset <nax> tims;

int dist[105][nax];

int main(){
    //cin.sync_with_stdio(0); cin.tie(nullptr);

    int n, m, l, t; scan(n); scan(m); scan(l); scan(t);

    for (int i=1; i<=n; i++){
        int x; scan(x); if (x) tims[i] = 1;
    }

    for (int i=0; i<m; i++){
        int a,b, c; scan(a); scan(b); scan(c);
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i=0; i<105; i++){
        for (int k=0; k<nax; k++){
            dist[i][k] = inf;
        }
    }

    dist[0][0] =0;

    int ans = inf;

    priority_queue <pair <int, pii>, vector <pair <int, pii>>, greater <pair <int, pii>>> q;
    q.push({0, {0, 1}});

    while (!q.empty()){
        auto node = q.top(); q.pop();

        int curDist = node.f, curAway = node.s.f, curNode = node.s.s;

        if (dist[curAway][curNode] < curDist || curAway > l || curDist >= ans) continue;

        if (curNode == n){
            ans = min(ans, curDist);
        }

        if (tims[curNode]){
            if (dist[0][curNode] > curDist+t){
                dist[0][curNode] = curDist+t;
                q.push({dist[0][curNode], {0, curNode}});
            }
        }

        for (pii nxt : graph[curNode]){
            if (nxt.s + curAway <= l){
                if (dist[nxt.s+curAway][nxt.f] > curDist+nxt.s){
                    dist[nxt.s+curAway][nxt.f] = curDist+nxt.s;
                    q.push({dist[nxt.s+curAway][nxt.f], {nxt.s+curAway, nxt.f}});
                }
            }
        }

    }


    if (ans == inf){
        cout << "-1\n";
    }
    else{
        cout << ans << "\n";
    }


}