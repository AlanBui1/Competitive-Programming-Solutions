#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>

const int MAXSZ = 1e5+5;

int N, a, b, c, dist, maxDist;
vector <pii> graph[MAXSZ];

void dfs(int curNode, int prevNode, int D){
    maxDist = max(maxDist, D);

    for (pii nxt : graph[curNode]){
        int nxtNode = nxt.first, nxtDist = nxt.second;
        if (nxtNode == prevNode) continue;
        dfs(nxtNode, curNode, D+nxtDist);
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=0; i<N; i++){
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        dist += c;
    }

    dist *= 2;
    dfs(0, 0, 0);
    cout << dist - maxDist << "\n";
}