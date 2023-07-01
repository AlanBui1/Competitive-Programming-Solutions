#include <bits/stdc++.h>
using namespace std;
const int nax = 1e7+5;
#define f first
#define s second
bool vis[nax];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >>n >> m;

    queue <pair <int, int>> q;
    q.push({n, 0});
    pair <int, int> node;

    while (!q.empty()){
        node = q.front(); q.pop();

        vis[node.f] = true;

        if (node.f == m){
            cout << node.s << "\n";
            return 0;
        }

        if (0 <= node.f*3 && node.f*3 <= nax){
            if (!vis[node.f*3]){
                vis[node.f*3] = 1;
                q.push({node.f*3, node.s+1});
            }
        }

        if (0 <= node.f-1 && node.f-1 <= nax){
            if (!vis[node.f-1]){
                vis[node.f-1] = 1;
                q.push({node.f-1, node.s+1});
            }
        }

        if (0 <= node.f-3 && node.f-3 <= nax){
            if (!vis[node.f-3]){
                vis[node.f-3] = 1;
                q.push({node.f-3, node.s+1});
            }
        }

        if (node.f %2 == 0 && 0 <= node.f/2 && node.f/2 <= nax){
            if (!vis[node.f/2]){
                vis[node.f/2] = 1;
                q.push({node.f/2, node.s+1});
            }
        }
    }
}