#include <bits/stdc++.h>
using namespace std;
const int nax = 5e5+5;

vector <pair <int, int>> graph[nax];
int longest_path, farthest_node, radius;

int dist[nax];

void dfs(int curNode, int prevNode, int curDist){
    dist[curNode] = curDist;

    if (curDist > longest_path){
        longest_path = curDist;
        farthest_node = curNode;
    }

    for (auto nxt : graph[curNode]){
        if (nxt.first == prevNode) continue;
        dfs(nxt.first, curNode, curDist+nxt.second);
    }
}

bool visited[nax], good[nax];

bool dfs2(int curNode, int prevNode){
    good[curNode] = false;
    visited[curNode] = true;
    if (curNode == farthest_node) return true;

    for (auto nxt : graph[curNode]){
        if (nxt.first != prevNode) good[curNode] |= dfs2(nxt.first, curNode);
    }

    return good[curNode];
}



int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i=0; i<n-1; i++){
        int a, b, d; cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }

    dfs(1, 1, 0);

    radius = 1e9;

    int start = farthest_node;
    
    dfs(farthest_node, farthest_node, 0);
    dfs2(start, start);
    for (int i=1; i<=n; i++){
        if (!visited[i]) dfs2(i,i);
        if (good[i]){
  
            radius = min(radius, max(dist[i], longest_path-dist[i]));
        }
        
    }


    cout << longest_path << "\n";
    cout << radius << "\n";
}