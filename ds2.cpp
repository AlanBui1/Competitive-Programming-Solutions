#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;

int parent[MAXSZ], ranking[MAXSZ];

int find(int i){
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a!=b){
        if (ranking[a] < ranking[b]){
            swap(a, b);
        }
        parent[b] = a;
        if (ranking[a] == ranking[b]){
            ranking[a]++;
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    vector <int> ans;

    for (int i=0; i<=n; i++){
        parent[i] = i;
        ranking[i] = 0;
    }

    int cnt = 0;
    for (int i=1; i<=m; i++){
        int u, v; cin >> u >> v;

        if (find(u) != find(v)){
            ans.push_back(i);
            unionsets(u, v);
            cnt++;
        }
    }
    if (cnt != n-1){
        cout << "Disconnected Graph" << "\n";
    }
    else{
        for (int i=0; i<n-1; i++){
            cout << ans[i] << "\n";
        }
    }
}