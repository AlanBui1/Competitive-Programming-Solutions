#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+5;

int parent[nax], SIZE[nax];

int find(int i){
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a!=b){
        if (SIZE[a] < SIZE[b]){
            swap(a, b);
        }
        parent[b] = a;
        SIZE[a] += SIZE[b];
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for (int i=0; i<nax; i++){
        parent[i] = i;
        SIZE[i] = 1;
    }

    int oper, u, v,x;
    while (q--){
        cin >> oper;

        if (oper == 1){
            cin >> u >> v;
            unionsets(u, v);
        }

        else{
            cin >> x;

            int ind = find(x);
            cout << SIZE[ind] << "\n";
        }
    }
}