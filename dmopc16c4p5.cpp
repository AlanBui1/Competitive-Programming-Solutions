#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
#define pii pair <int, int>
#define f first
#define se second
const int inf = 1e9;

struct edge{
    int a, b, d;
};

bool compare(edge x, edge y){
    return x.d > y.d;
}

vector <edge> edges;
int n, m, parent[MAXSZ], siz[MAXSZ], dist[MAXSZ];
vector <pii> graph[MAXSZ];

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
}

void dfs(int curNode, int prevNode, int minUsed){
    dist[curNode] = min(dist[curNode], minUsed);

    for (pii nxt : graph[curNode]){
        if (prevNode != nxt.f){
            dfs(nxt.f, curNode, min(minUsed, nxt.se));
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        edge E;
        cin >> E.a >> E.b >> E.d;
        edges.push_back(E);
    }

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i; siz[i] = 1; dist[i] = inf;
    }

    sort(edges.begin(), edges.end(), compare);
    int needtoconnect = n;

    for (int i=0; i<m; i++){
        if (!needtoconnect) break;

        if (find(edges[i].a) != find(edges[i].b)){
            graph[edges[i].a].push_back({edges[i].b, edges[i].d});
            graph[edges[i].b].push_back({edges[i].a, edges[i].d});
            unionsets(edges[i].a, edges[i].b);
            needtoconnect--;
        }
    }

    dfs(1, 1, inf);

    cout << 0 << "\n";
    for (int i=2; i<=n; i++){
        cout << dist[i] <<"\n";
    }

}