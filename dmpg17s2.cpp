#include <bits/stdc++.h>
using namespace std;
const int MAXSZ= 1e5+5;
int parent[MAXSZ];

int find(int v){
    if (parent[v] == v){
        return v;
    }
    return parent[v] = find(parent[v]);
}

void union_sets(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n, q;
    cin >> n >> q;

    for (int i=1; i<=n; i++){
        parent[i] = i;
    }
    int x, y;
    while (q--){
        char oper; cin >> oper;

        if (oper == 'A'){
            cin >> x >> y;
            union_sets(x, y);
        }

        else if (oper == 'Q'){
            cin >> x >> y;
            if (find(x) == find(y)) cout << "Y\n" ;
            else cout << "N\n";
        }
    }
}