#include <bits/stdc++.h>
using namespace std;

const int nax = 1e4+5;
vector <int> graph[nax];

int farthest, starter, dist[nax];

void dfs(int curNode, int prevNode, int curDist){
    if (curDist > farthest){
        farthest = curDist;
        starter = curNode;
    }

    for (int nxt : graph[curNode]){
        if (nxt != prevNode){
            dfs(nxt, curNode, curDist+1);
        }
    }
}



int main() {
    int n; cin >> n;

    for (int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;

        graph[a].push_back(b);graph[b].push_back(a);
    }

    dfs(1, 1, 0);
    dfs(starter, starter, 0);
    cout << farthest << "\n";
}