#include <bits/stdc++.h>
using namespace std;
const int nax = 1000;
#define f first
#define s second
#define pii pair <int, int>

int parent[nax], siz[nax];
pii buildings[nax];

int find(int a){
    return a == parent[a] ? a: parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);

    if (a!=b){
        if (siz[a] > siz[b]){
            swap(a, b);
        }
        parent[b] = a;
        siz[a] += siz[b];
    }
}

vector <pair <double, pii>> graph;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=0; i<nax; i++){
        parent[i] = i;
        siz[i] = 1;
    }

    for (int i=0; i<n; i++){
        cin >> buildings[i].f >> buildings[i].s;
    }

    for (int i=0; i<n; i++){
        for (int k=i+1; k<n; k++){
            double dx = buildings[i].f-buildings[k].f, dy = buildings[i].s-buildings[k].s;
            double dist = sqrt((dx*dx) + (dy*dy));
            graph.push_back({dist,{i, k}});
        }
    }

    sort(graph.begin(), graph.end());

    int m; cin >> m;
    int x, y;

    int connected = 0;

    for (int i=0; i<m; i++){
        cin >> x >> y;
        x--; y--;
        if (find(x) != find(y)) connected++;
        unionsets(x, y);
    }

    double ans = 0;

    vector <pii> toconnect;

    int cur = -1;

    while (connected != n-1){
        cur++;
        if (find(graph[cur].s.f) == find(graph[cur].s.s)){
            continue;
        }
        toconnect.push_back({graph[cur].s.f, graph[cur].s.s});
        ans += graph[cur].f;
        unionsets(graph[cur].s.f, graph[cur].s.s);
        connected++;
    }

    cout << fixed << setprecision(2) << ans <<"\n";
    for (pii c : toconnect){
        cout << c.f+1 << " " << c.s+1 << "\n";
    }


}