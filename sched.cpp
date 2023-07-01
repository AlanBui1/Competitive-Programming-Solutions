#include <bits/stdc++.h>
using namespace std;

#define pii pair <int,int>
const int INF = 2e9;
int N, M, K, dist[205][205];
vector <pii> graph[205];

struct event{
    int location, startTime, length;
}events[10005];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=0; i<M; i++){
        int a, b, d; cin >> a >> b >> d;

        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    cin >> K;
    for (int i=1; i<=K; i++){
        cin >> events[i].location >> events[i].startTime >> events[i].length;
    }

    for (int i=1; i<=N; i++){
        for (int k=1; k<=N; k++){
            dist[i][k] = INF;
        }
        priority_queue<pii, vector <pii>, greater<pii>> pq;
        pq.push({0, i});
        dist[i][i] = 0;

        while (!pq.empty()){
            auto top = pq.top(); pq.pop();
            int curNode = top.second, curDist = top.first;

            for (pii nxt : graph[curNode]){
                int nxtNode = nxt.first, nxtDist = nxt.second;

                if (dist[i][nxtNode] > curDist + nxtDist){
                    dist[i][nxtNode] = curDist + nxtDist;
                    pq.push({dist[i][nxtNode], nxtNode});
                }
            }
        }
    }

    int curLocation = 1, curTime = 0;

    for (int i=1; i<=K; i++){
        int LOCATION = events[i].location, START = events[i].startTime, TIME = events[i].length;

        if (curTime + dist[curLocation][LOCATION] <= START){
            curTime = START + TIME;
            curLocation = LOCATION;
            cout << i << "\n";
        }
    }
}