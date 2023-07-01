#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXSZ = 2e5+5;

int N, a[MAXSZ], connects[MAXSZ], connects2[MAXSZ];
vector <int> graph[MAXSZ], rgraph[MAXSZ];

int dfs(int curNode){
    if (connects[curNode]) return connects[curNode];
    connects[curNode] = a[curNode];
    for (int nxt : graph[curNode]){
        connects[curNode] += dfs(nxt);
    }
    return connects[curNode];
}

int dfs2(int curNode){
    if (connects2[curNode]) return connects2[curNode];
    for (int nxt : rgraph[curNode]){
        connects2[curNode] += dfs2(nxt);
    }
    connects2[curNode] += a[curNode];
    return connects2[curNode];
}

signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> a[i];
    }

    for (int i=0; i<N-1; i++){
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }

    for (int i=1; i<=N; i++){
        dfs(i);
        dfs2(i);
    }

    int tot =0, best = 0;

    for (int i=1; i<=N; i++){
        tot += (connects[i] - 1) * (a[i]);
        for (int k : graph[i]){
            //cout << i << " " << k << " " << connects2[i] << " " << connects2[k] << " " << connects2[k] - connects2[i] << " " << connects2[i] * (connects2[k] - connects2[i]) << "\n";
            best = max(best, (connects2[k] - connects2[i]) * (connects[i] - connects[k]));
        }
       // cout << connects2[i] << " ";
    }//cout << "\n";

    cout << tot +best << "\n";
}