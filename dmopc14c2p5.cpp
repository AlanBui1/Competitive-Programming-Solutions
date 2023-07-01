#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6+5;

vector <int> graph[nax];
double paths[nax];
double dp[nax];

double dfs(int curNode){
    if (curNode == 1){
        return 1;
    }
    if (dp[curNode] != -1){
        return dp[curNode];
    }
    double ret =0;
    for (int nxt : graph[curNode]){
        ret += dfs(nxt)/paths[nxt];
    }
    dp[curNode] = ret;
    return ret;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y;

        paths[x]++;
        graph[y].push_back(x);
    }
    for (int i=0; i<nax; i++){
        dp[i] =-1;
    }

    for (int i=1; i<=n; i++){
        if (!paths[i]){
            cout << fixed << setprecision(10) << dfs(i) << "\n";
        }
    }
}