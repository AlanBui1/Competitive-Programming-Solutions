#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;

vector <pair <int, int>> graph[MAXSZ];
bool good[MAXSZ];
int cost[MAXSZ];

bool prune(int curNode, int prevNode){

    for (pair <int, int> nxt : graph[curNode]){
        if (nxt.first != prevNode){
            good[curNode] |= prune(nxt.first, curNode);
        }
    }
    return good[curNode];
}

int dfs(int curNode, int prevNode, int curDist){
    cost[curNode] = curDist;

    for (pair <int, int> nxt : graph[curNode]){
        if (!good[nxt.first]) continue;
        if (nxt.first != prevNode){
            cost[curNode] += dfs(nxt.first, curNode, nxt.second);
        }
    }
    return cost[curNode];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    int a, b, d;
    for (int i=0; i<n-1; i++){
        cin >> a >> b >> d;

        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    int item;
    for (int i=0; i<k; i++){
        cin >> item;
        good[item] = 1;
    }

    prune(1, 1);
    dfs(1, 1, 0);

    cout << cost[1] << "\n";

}