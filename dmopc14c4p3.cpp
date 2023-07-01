#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair <ll, ll>
#define f first
#define s second
const ll inf = 1e18;
const int MAXSZ=1005;

ll grid[MAXSZ][MAXSZ];
ll dist[MAXSZ][MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int l, d; cin >> l >> d;

    for (int i=0; i<d; i++){
        for (int k=0; k<l; k++){
            cin >> grid[i][k];
        }
    }

    priority_queue <pair<ll, pii>, vector <pair <ll, pii>>, greater <pair <ll, pii>>>pq;
    pq.push({grid[0][0], {0, 0}});

    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<MAXSZ; k++){
            dist[i][k] = inf;
        }
    }

    dist[0][0] =  grid[0][0];

    while (!pq.empty()){
        auto node = pq.top(); pq.pop();
        int curDist = node.f, curL = node.s.s, curD = node.s.f;

        if (dist[curD][curL] < curDist) continue;

        if (curD+1 < d){
            if (dist[curD+1][curL] > curDist+grid[curD+1][curL]){
                dist[curD+1][curL] = curDist+grid[curD+1][curL];
                pq.push({dist[curD+1][curL], {curD+1, curL}});
            }
        }

        if (curL + 1 < l){
            if (dist[curD][curL+1] > curDist+grid[curD][curL+1]){
                dist[curD][curL+1] = curDist+grid[curD][curL+1];
                pq.push({dist[curD][curL+1], {curD, curL+1}});
            }
        }

        if (curL -1 >= 0){
            if (dist[curD][curL-1] > curDist+grid[curD][curL-1]){
                dist[curD][curL-1] = curDist+grid[curD][curL-1];
                pq.push({dist[curD][curL-1], {curD, curL-1}});
            }
        }
    }
    int a, b; cin >> a >> b;
    cout << dist[b][a] << "\n";

}