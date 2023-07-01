#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+5;
int parent[nax];

int find(int u){
    return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void unionsets(int u, int v){
    u = find(u); v = find(v);
    if (u != v) parent[v] = u;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int q=2;

    while (q--){
        int n; cin >> n;
        for (int i=0;i <=n; i++) parent[i] = i;
        int ans = n;

        for (int i=1; i<=n; i++){
            int x; cin >> x;

            if (find(x) != find(i)){
                unionsets(x, i);
                ans--;
            }
        }

        cout << ans << " ";
    }
    cout << "\n";
}