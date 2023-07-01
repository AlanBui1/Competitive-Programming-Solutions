#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=4e5+5;

vector <int> graph[MAXSZ];
int dist[MAXSZ], vals[MAXSZ];
bool visited[MAXSZ];

int dfs(int curNode, int curDist){
    visited[curNode] = 1;

    dist[curNode] = curDist;

    for (int nxt : graph[curNode]){
        dist[curNode] += dfs(nxt, vals[nxt]);
    }
    
    return dist[curNode];
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int a, b;
    for (int i=0; i<n-1; i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
    }

    for (int i=0; i<n; i++) cin >> vals[i];

    int ans = -1005;

    for (int i=0; i<n; i++){
        if (visited[i]){
            ans = max(ans, dist[i]);
        }

        else{
            dfs(i, vals[i]);
            ans = max(ans, dist[i]);
        }
    }
    cout << ans << "\n";
}