#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;

vector <int> graph[MAXSZ];

bool vis1[MAXSZ], vis2[MAXSZ];

void dfs1(int curNode){
    vis1[curNode] = true;

    for (int i : graph[curNode]){
        if (!vis1[i]){
            dfs1(i);
        }
    }
}

void dfs2(int curNode){
    vis2[curNode] = true;

    for (int i : graph[curNode]){
        if (!vis2[i]){
            dfs2(i);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);cin.tie(0);

    int n, m; cin >> n >>m;

    for (int i=0; i<m; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
    }

    int p, q; cin >> p >> q;

    dfs1(p);
    dfs2(q);

    if (vis1[q]){
        cout << "yes\n";
    }
    else if (vis2[p]){
        cout << "no\n";
    }
    else{
        cout << "unknown\n";
    }
}