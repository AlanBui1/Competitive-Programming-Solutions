#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXSZ=1e5+5;

int parent[MAXSZ], siz[MAXSZ], arr[MAXSZ];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b = find(b);
    if (a == b) return;
    if (siz[a] > siz[b]){
        swap(a, b);
    }
    parent[b] = a;
    siz[a] += siz[b];
}


int32_t main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector <pair <int, pair <int, int>>> graph;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        siz[i] = 1;
        parent[i] = i;
        if (i >= 1){
            graph.push_back({abs(arr[i]-arr[i-1]), {i, i-1}});
        }
    }

    int needtoconnect = n;

    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y; x--; y--;
        if (find(x) != find(y)){
            unionsets(x, y);
            needtoconnect--;
        } 
        
    }

    int mstCost = 0;

    sort(graph.begin(), graph.end());

    for (int i=0; i<graph.size(); i++){
        if (!needtoconnect) break;
        if (find(graph[i].second.first) != find(graph[i].second.second)){
            needtoconnect--;
            unionsets(graph[i].second.first, graph[i].second.second);
            mstCost += graph[i].first;
        }
    }

    cout << mstCost << "\n";
}