#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 105;

int parent[MAXSZ], siz[MAXSZ];

int findset(int a){
    if (a == parent[a]){
        return a;
    }
    return parent[a] = findset(parent[a]);
}

void unionsets(int a, int b){
    a = findset(a); b = findset(b);

    if (a != b){
        if (siz[a] < siz[b]){
            swap(a, b);
        }
        siz[a] += siz[b];
        parent[b] = a;
    }
}

struct edges{
    int a, b, dist;
};

bool compare(edges x, edges y){
    return x.dist < y.dist;
}

void solve(){
    int n, c; cin >> n >> c;

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    vector <edges> edgeList;
    for (int i=0; i<c; i++){
        edges E;
        cin >> E.a >> E.b >> E.dist;
        edgeList.push_back(E);
    }

    sort(edgeList.begin(), edgeList.end(), compare);

    int components = n;
    int ans = 0;
    for (edges E : edgeList){
        if (findset(E.a) != findset(E.b)){
            components--;
            unionsets(E.a, E.b);
            ans += E.dist;
        }
    }

    if (components == 1){
        cout << ans << "\n";
    }
    else{
        cout << "Requires more conduits\n";
    }


}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--){
        solve();
    }
}