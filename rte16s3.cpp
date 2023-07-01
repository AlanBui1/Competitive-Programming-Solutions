#include <bits/stdc++.h>
using namespace std;
const int nax = 6000;
#define ll long long
const ll inf = 1e18;

vector <pair <int, int>> graph[nax];
bool visited[nax];
ll dist[nax];

void dfs(int curNode, ll curDist){
    visited[curNode] = true;

    for (auto nxt : graph[curNode]){
        if (! visited[nxt.first]){
            if (dist[nxt.first] > curDist+nxt.second){
                dist[nxt.first] = curDist+nxt.second;
                dfs(nxt.first, curDist+nxt.second);
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q;
    cin >> n;
    int a, b, d;

    for (int i=0; i<n-1; i++){
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    for (int i=0; i<n; i++){
        dist[i]= 1e18;
    }

    vector <pair <pair <int, int>, int>> queries;

    cin >> q;
    int x, y;
    for (int i=0; i<q; i++){
        cin >> x >> y;
        if (x > y) swap(x, y);
        queries.push_back({{x, y}, i});
    }

    sort(queries.begin(), queries.end());

    int curQ = queries[0].first.first;
    
    for (int i=0; i<n; i++) dist[i] = inf;
    dist[curQ] = 0;
    dfs(curQ, 0);

    ll ans[q];

    for (int i=0; i<q; i++){
        if (curQ == queries[i].first.first){
            ans[queries[i].second] =  dist[queries[i].first.second];
        }
        else{
            for (int k=0; k<n; k++){
                dist[k] = inf;
                visited[k] = 0;
            }
            dist[queries[i].first.first] = 0;
            curQ = queries[i].first.first;
            dfs(curQ, 0);
            ans[queries[i].second] = dist[queries[i].first.second];
        }
    }
    for (int i=0; i<q; i++){
        cout << ans[i] << "\n";
    }
}