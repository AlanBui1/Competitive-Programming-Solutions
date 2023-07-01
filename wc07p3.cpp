#include <bits/stdc++.h>
using namespace std;
const int MOD = 13371337;

vector <int> graph[20];
int ways[20][1<<17];
int n;
int dfs(int curNode, int mask){
    if (curNode == n-1){
        return 1;
    }

    if (ways[curNode][mask] != -1){
        return ways[curNode][mask];
    }

    ways[curNode][mask] = 0;
    for (int nxt : graph[curNode]){
        if (!(mask&(1<<nxt))){
            ways[curNode][mask] += dfs(nxt, mask | (1<<nxt));
            ways[curNode][mask] %= MOD;
        }
    }
    return ways[curNode][mask];
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--){
        cin >> n;
        for (int i=0; i<20; i++){
            graph[i].clear();
        }
        memset(ways, -1, sizeof(ways));
        int x;
        
        for (int i=0; i<n; i++){
            for (int k=0; k<n; k++){
                cin >> x;
                if (x){
                    graph[i].push_back(k);
                }  
            }
        }

        cout << dfs(0, 1) << "\n";

    }
}