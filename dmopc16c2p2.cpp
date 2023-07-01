#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;

int parent[MAXSZ], ranking[MAXSZ];

int find(int a){
    if (parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a]);
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

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
        ranking[i] = 0;
    }

    for (int i=0; i<m; i++){
        int k; cin >> k;
        k--;
        int u, f; cin >> f;
        while (k--){
            cin >> u;
            unionsets(u, f);
        }
    }
    vector <int> ans;
    int cnt=0;
    for (int i=1; i<=n; i++){
        if (find(i) == find(1)){
            ans.push_back(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i=0; i<cnt-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[cnt-1] << "\n";
    
}