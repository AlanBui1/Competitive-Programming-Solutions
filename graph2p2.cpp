#include <bits/stdc++.h>
using namespace std;

vector <int> graph[1005];
bool vis[1005], visited[1005];

bool dfs(int curNode){
    vis[curNode] = 1;
    visited[curNode] = 1;
    bool ret = false;
    for (int nxt : graph[curNode]){
        if (vis[nxt]){
            ret = true;
            break;
        }
        if (!visited[nxt]) ret |= dfs(nxt);
    }
    vis[curNode] = false;

    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    bool has;
    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            cin >> has;
            if (has) graph[i].push_back(k);
        }
    }

    for (int i=0; i<n; i++){
        if (visited[i]) continue;

        if (dfs(i)){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";


}