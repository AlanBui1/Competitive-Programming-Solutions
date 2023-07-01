#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;

int n, m;
vector <int> graph[MAXSZ];
bool haspho[MAXSZ];

bool findPho(int curNode, int prevNode){
    
    for (auto nxt : graph[curNode]){
        if (prevNode != nxt) haspho[curNode] |= findPho(nxt, curNode);
    }

    return haspho[curNode];
}

int diameter, endpoint, dist[MAXSZ];

void dfs(int curNode, int prevNode, int curDist){
    dist[curNode] = curDist;

    if (curDist > diameter){
        diameter = curDist;
        endpoint = curNode;
    }

    for (auto nxt : graph[curNode]){
        if (prevNode == nxt || !haspho[nxt]) continue;
        dfs(nxt, curNode, curDist+1);
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    int rest;
    for (int i=0; i<m; i++){
        cin >> rest;
        haspho[rest] = true;
    }

    for (int i=0; i<n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); 
        graph[b].push_back(a);
    }

    findPho(rest, rest);

    int r=0;
    for (int i=0; i<n; i++){
        if (haspho[i]) r++;       
    }

    dfs(rest, rest, 0);
    dfs(endpoint, endpoint, 0);
    
    cout << (r-1)*2 - diameter << "\n";

}