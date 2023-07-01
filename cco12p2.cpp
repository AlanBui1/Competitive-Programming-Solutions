#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=20005;
const int inf = 1e9;
#define f first
#define s second
#define scan(x) do{while((x = getchar()) < '0'); for (x -= '0'; '0' <= (_=getchar()); x = (x<<3)+(x<<1)+_-'0');}while(0)
char _;

vector <pair<int, int>> graph[20005];

int second = inf;
int dist[MAXSZ][2];

void solve(int s, int d, int e){

    priority_queue <pair <int, int>,vector <pair <int, int>>, greater <pair <int, int>>> pq;
    pq.push({d, s});

    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<2; k++){
            dist[i][k] = inf;
        }
    }
    dist[0][0] = 0; dist[0][1] = inf;

    pair <int, int> node;
    int curNode, curDist, nxtNode, nxtDist;

    while (!pq.empty()){
        node = pq.top(); pq.pop();

        curNode = node.s; curDist = node.f;
       
        for (pair <int, int> nxt : graph[curNode]){
            nxtNode = nxt.f; nxtDist = nxt.s;

            if (dist[nxtNode][0] > curDist + nxtDist){
                dist[nxtNode][1] = dist[nxtNode][0];
                dist[nxtNode][0] = curDist + nxtDist;
                pq.push({dist[nxtNode][0], nxtNode});
            }

            else if (dist[nxtNode][1] > curDist + nxtDist && curDist+nxtDist != dist[nxtNode][0]){
                dist[nxtNode][1] = curDist + nxtDist;
                pq.push({dist[nxtNode][1], nxtNode});
            }
        }  
    }

    second = dist[e][1];

    if (second == inf){
        cout << -1 << "\n";
    }
    else{
        cout << second << "\n";
    }


}

int main() {
  
  int n, m;
  scan(n);
  scan(m);
//   cin >> n >> m;

  int node1, node2, weight;
  for (int i=0; i<m; i++){
    scan(node1);
    scan(node2);
    scan(weight);
    // cin >> node1 >> node2 >> weight;
    graph[node1-1].push_back({node2-1, weight});
  }

  solve(0, 0, n-1);
  
}