#include <bits/stdc++.h>
using namespace std;

const int MAXSZ=2e5+5;

int parent[MAXSZ], siz[MAXSZ], cnt=0;

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);
    if (a != b){
        if (siz[a] > siz[b]) swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
    }
    else{
        cnt++;
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    for (int i=0; i<m; i++){
        int u, v; cin >> u >> v;
        unionsets(u, v);
    }

    if (cnt <= 1) cout << "YES\n";
    else cout << "NO\n";

}