#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
const int MAXSZ = 1005;

struct info{
    int dist, nodes;
}dists[MAXSZ];

bool compare(info x, info y){ //returns true if x is better than y
    if (x.dist == y.dist){
        return x.nodes > y.nodes;
    }
    return x.dist > y.dist;
}

int N, M;
bool vis[MAXSZ], flag = 0;
vector <pii> graph[MAXSZ];

void dfs(int curNode, int curStops, int curDist){
    if (vis[curNode]){
        flag = 1;
        return;
    }
    vis[curNode] = 1;

    for (pii nxt : graph[curNode]){
        int nxtDist = nxt.second, nxtNode = nxt.first;

        info test = {nxtDist + curDist, curStops+1};

        if (compare(test, dists[nxtNode])){
            dists[nxtNode] = test;
            dfs(nxtNode, curStops + 1, nxtDist + curDist);
        }
    }
    vis[curNode] = 0;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;
    for (int i=1; i<=M; i++){
        int a, b, d; cin >> a >> b >> d;
        graph[a].push_back({b, d});
    }

    dfs(1, 1, 0);

    if (flag || dists[N].nodes == 0){
        cout << "-1\n";
    }
    else{
        cout << dists[N].dist << " " << dists[N].nodes << "\n";
    }
}