#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 2e5+5;
vector <int> graph[MAXSZ], order;
bool vis[MAXSZ];
int N;

void dfs(int curNode){
    if (vis[curNode]) return;
    vis[curNode] = 1;

    for (int nxt : graph[curNode]){
        dfs(nxt);
    }

    order.push_back(curNode);
}



int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i=1; i<=N; i++){
        int x; cin >> x;
        while (x--){
            int c; cin >> c;
            graph[c].push_back(i);
        }
    }

    for (int i=1; i<=N; i++){
        if (vis[i]) continue;

        dfs(i);
    }

    for (int i=N-1; i>=0; i--){
        cout << order[i] << " ";
    }

}