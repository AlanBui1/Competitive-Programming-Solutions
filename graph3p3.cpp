#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 105;

struct edge{
    int a, b, danger, cost;
};

vector <edge> edges;

bool compare(edge x, edge y){
    if (x.danger == y.danger){
        return x.cost < y.cost;
    }
    return x.danger < y.danger;
}

int parent[MAXSZ], siz[MAXSZ];

int findSet(int a) {
    return parent[a] == a ? a : parent[a] = findSet(parent[a]);
}

void unionsets(int a, int b){
    a = findSet(a); b = findSet(b);

    if (a != b){
        if (siz[a] > siz[b]){
            swap(a, b);
        }
        siz[b] += siz[a];
        parent[a] = b;
    }
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for (int i=1; i<=N; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    for (int i=0;i <M; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        edges.push_back({a, b, d, c});
    }

    sort(edges.begin(), edges.end(), compare);
    int cost = 0, dang = 0;

    for (edge E : edges){
        int A = findSet(E.a), B = findSet(E.b);
        if (A == B) continue;

        cost += E.cost;
        dang += E.danger;
        unionsets(A, B);
    }

    cout << dang << " " << cost << "\n";

}