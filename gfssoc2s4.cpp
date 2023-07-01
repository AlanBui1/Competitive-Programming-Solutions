#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=5e5+5;
#define ll long long
const ll inf = INT_MAX-10;

vector <pair < pair<int, int>, bool>> graph[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    int a, b, k;

    for (int i=0; i<m; i++){
        cin >> a >> b >> k;
        graph[a].push_back({{k, b}, 0});
    }

    int d; cin >> d;

    for (int i=0; i<d; i++){
        cin >> a >> b >> k;
        graph[a].push_back({{k, b}, 1});
    }

    priority_queue <pair <pair <int, int>, bool>, vector <pair <pair <int, int>, bool>>, greater <pair <pair <int, int>, bool>>> pq;
    
    pq.push({{0, 1}, 0});

    long long dist[2][MAXSZ];
    for (int i=0; i<2; i++){
        for (int k=0; k<MAXSZ; k++){
            dist[i][k] = inf;
        }
    }
    dist[0][1]= 0;

    while (!pq.empty()){
        pair <pair <int, int>, bool> node = pq.top();
        pq.pop();
        int curDist = node.first.first;
        int curNode = node.first.second;
        bool curUsed = node.second;

        for (pair <pair <int, int>, bool> nxt : graph[curNode]){
            int nxtDist = nxt.first.first;
            int nxtNode = nxt.first.second;
            bool willuse = nxt.second;

            if (willuse){
                if (curUsed){
                    continue;
                }

                else{
                    if (dist[1][nxtNode] > dist[0][curNode]+nxtDist){
                        dist[1][nxtNode] = dist[0][curNode]+nxtDist;
                        pq.push({{dist[1][nxtNode],nxtNode}, 1});
                    }
                }
            }

            else{
                if (curUsed){
                    if (dist[1][nxtNode] > dist[1][curNode]+nxtDist){
                        dist[1][nxtNode] = dist[1][curNode]+nxtDist;
                        pq.push({{dist[1][nxtNode], nxtNode}, 1});
                    }
                }

                else{
                    if (dist[0][nxtNode] > dist[0][curNode]+nxtDist){
                        dist[0][nxtNode] = dist[0][curNode]+nxtDist;
                        pq.push({{dist[0][nxtNode], nxtNode}, 0});
                    }
                }
            }
        }    
    }

    ll ans = min(dist[1][n], dist[0][n]);
    if (ans == inf){
        cout << -1 << "\n";
    }
    else{
        cout << ans << "\n";
    }
}