#include <bits/stdc++.h>
using namespace std;

const int nax = 1e5+5;

int parent[nax];
bitset <nax> vis;

#define pii pair <int, int>
#define f first
#define s second

int solve(int cur, int cnt){
    if (parent[cur] == -1) return cnt;

    if (vis[parent[cur]]) return -1;

    vis[parent[cur]] = 1;
    return solve(parent[cur], cnt+1);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int n, m, p; cin >> n >> m >> p;
    vis[p] = 1;

    for (int i=0; i<nax; i++){
        parent[i] = -1;
    }

    for (int i=0; i<n; i++){
        int a, b; cin >> a >> b;
        if (parent[b] == -1){
            parent[b] = a;
        }
    }

    cout << solve(p, 0) << "\n";

}