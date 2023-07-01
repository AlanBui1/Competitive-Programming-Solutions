#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 105;
#define pii pair <int, int>
#define f first
#define s second

int parent[MAXSZ];
vector <pii> edges;

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);
    if (a!= b){
        parent[b] = a;
    }
}

int comps(int n, int m, int skip){
    int comp = n;

    for (int i=0;i<MAXSZ; i++){
        parent[i] = i;
    }

    for (int i=0; i<m; i++){
        pii e = edges[i];
        if (i == skip) continue;
        if (find(e.f) == find(e.s)){
            continue;
        }
        unionsets(e.f, e.s);
        comp -= 1;

    }

    return comp;
}

int bridges(int n, int m){
    int ret = 0;

    if (comps(n, m, MAXSZ) != 1) return 0;

    for (int i=0; i<m; i++){
        if (comps(n, m, i) != 1){
            ret ++;
        }
    }

    return ret;
}


int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m;

    for (int i=0; i<5; i++){
        edges.clear();
        cin >> n >> m;
        for (int k=0; k<m; k++){
            int a, b; cin >> a >> b;
            edges.push_back({a, b});
        }
        cout << bridges(n, m) << "\n";
    }


}