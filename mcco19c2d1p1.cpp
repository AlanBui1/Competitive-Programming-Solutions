#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6;
#define f first
#define s second

int n, m, k, x;
int parent[nax], siz[nax];
vector <int> order, ans, graph2[nax];
vector <pair <int, int>> graph;

bool destroyed[nax];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void unionsets(int a, int b){
    a = find(a); b= find(b);

    if (a != b){
        if (siz[a] > siz[b]){
            swap(a, b);
        }
        parent[b] = a;
        siz[a] += siz[b];
        n--;
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int a, b; cin >> a>> b;
        graph.push_back({a, b});
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }

    for (int i=0; i<n; i++){
        siz[i] = 1;
        parent[i] =i;
    }

    cin >> k;
    for (int i=0; i<k; i++){
        cin >> x;
        order.push_back(x);
        destroyed[x]= 1;
    }

    reverse(order.begin(), order.end());
    for (pair <int ,int> edge : graph){
        if (destroyed[edge.f] || destroyed[edge.s]) continue;
        unionsets(edge.f, edge.s);
    }

    ans.push_back(n-k);

    for (int nxt : order){
        destroyed[nxt] = false;

        for (int node : graph2[nxt]){
            if (destroyed[nxt] || destroyed[node]) continue;
            unionsets(node, nxt);
        }
        n++;
        ans.push_back(n-k);
    }

    reverse(ans.begin(), ans.end());
    for (int i : ans){
        cout << i << "\n";
    }


}