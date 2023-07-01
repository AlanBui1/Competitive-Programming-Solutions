#include <bits/stdc++.h>
using namespace std;
const int maxn = 19;

int dp[1 << maxn];
int n, m;
vector <int> graph[maxn];

void dfs(int mask, int cur, int node, int offMask){

    // cout << mask << " " << cur << " " << node << " " << offMask <<  "\n";

    for (int nxt : graph[node]){
        offMask |= 1 << nxt;
    }

    if (dp[mask] != 0) return;
    dp[mask] = cur;
    for (int i=0; i<n; i++){

        if (offMask & (1 << i)) continue;
        if (mask & (1 << i)) continue;

        if (i != node){
            dfs(mask ^ (1 << i), cur+1, i, offMask);
        }
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a, b; cin >> a>> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    int ans = 0;
    
    for (int i=0; i<n; i++){
        dfs(1 << i, 1, i, 0);
    } 
    for (int i=0; i<1<<maxn; i++) ans = max(ans, dp[i]);
    cout << ans << "\n";
}