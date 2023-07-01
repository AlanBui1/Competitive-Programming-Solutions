#include <bits/stdc++.h>
using namespace std;

int n, m, k, a, b;
vector <int> graph[200005];

int main() {
  cin >> n >> m >> k >> a >> b;
  int stop;
  int stops[k];
  for (int i=0; i<k; i++){
    cin >> stop;
    stops[i] = stop;
  }  
  int node1, node2;
  for (int i=0; i<m; i++){
    cin >> node1 >> node2;
    graph[node1-1].push_back(node2-1);
    graph[node2-1].push_back(node1-1);
  }
  int dist[n], dist2[n];
  for(int i=0; i<n; i++){
    dist[i] = INT_MAX;
    dist2[i] = INT_MAX;
  }
  dist[a-1] = 0;
  dist2[b-1] = 0;
  queue <int> q;
  q.push(a-1);

  while (!q.empty()){
    int curNode = q.front();
    q.pop();
    for (int i : graph[curNode]){
      if (dist[i] > dist[curNode]+1){
        dist[i] = dist[curNode]+1;
        q.push(i);
      }
    }
  }

  queue <int> q2;
  q2.push(b-1);
  while (!q2.empty()){
    int curNode = q2.front();
    q2.pop();
    for (int i : graph[curNode]){
      if (dist2[i] > dist2[curNode]+1){
        dist2[i] = dist2[curNode]+1;
        q2.push(i);
      }
    }
  }
  int ans=INT_MAX;
  for (int i : stops){
    ans = min(ans, dist[i-1]+dist2[i-1]);
  }
  cout << ans << "\n";
}