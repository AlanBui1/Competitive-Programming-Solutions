#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;

int n, m;
vector <int> graph[MAXSZ];
int dp[MAXSZ];

int dfs(int curNode){
    if (dp[curNode] != -1) return dp[curNode];

    for (int nxt : graph[curNode]){
        dp[curNode] = max(dp[curNode], dfs(nxt)+1);
    }

    return dp[curNode];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<=n; i++){
        dp[i] = -1;
    }

    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        ans = max(ans, dfs(i));
    }

    cout << ans+1 <<"\n";
}