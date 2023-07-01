#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define ll long long
#define f first
#define s second
#define pii pair <ll,ll>
const ll inf = 1e18;

ll dist[MAXSZ];

vector <pii> graph[MAXSZ];

ll cost (ll km){
    ll s = 0;
    if (km >= 10){
        s += 20;
        km -= 10;
        s += km;
    }
    else{
        s += 2*km;
    }
    return s;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int v, e, p, d, r;
    cin >> v >> e >> p >> d >> r;
    ll a, b, c;

    for (int i=0; i<e; i++){
         cin >> a >> b >> c;
         graph[a].push_back({b, c});
         graph[b].push_back({a, c});
    }

    priority_queue <pii, vector <pii>, greater <pii>> q;
    q.push({0, d});

    for (int i=0; i<MAXSZ; i++) dist[i] = inf;
    dist[d] = 0;

    while (!q.empty()){
        auto node = q.top(); q.pop();

        ll curDist = node.f, curNode = node.s;

        if (curDist > dist[curNode]) continue;

        for (auto nxt : graph[curNode]){
            if (dist[nxt.f] > curDist+nxt.s){
                dist[nxt.f] = curDist+nxt.s;
                q.push({dist[nxt.f], nxt.f});
            }
        }
    }

    if (dist[p] >= inf){
        cout << "Nooooooooo!!!\n";
    }
    else if (dist[r] >= inf){
        cout << cost(dist[p])+3 << "\n";
        cout << "Yippee!!!\n";
    }
    else{
        cout << cost(dist[p]+dist[r])+3 << "\n";
    }
}