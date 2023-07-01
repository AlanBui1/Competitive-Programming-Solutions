#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+5;

int parent[nax], siz[nax];

int find(int a){
    if (parent[a] == a) return a;
    return parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a!=b){
        if (siz[a] > siz[b]){
            swap(a, b);
        }
        parent[b] = a;
        siz[a] += b;
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n>>m>>k;

    string race; cin >> race;

    for (int i=0; i<nax; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    for (int i=0; i<m; i++){
        int a,b; cin >> a >> b;
        if (race[a-1] == race[b-1]){
            unionsets(a, b);
        }
    }
    int ans = 0;
    for (int i=0; i<k; i++){
        int x, y; cin >> x >> y;

        if (find(x) == find(y)) ans++;       
    }
    cout << ans << "\n";

}