#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+5;

vector <int> groups[nax], conv[nax];

bitset <nax> visited;
#define pii pair <int, int>

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, k, m; cin >> n >> k >> m;

    for (int i=0; i<m; i++){
        for (int j=0; j<k; j++){
            int x; cin >> x;
            groups[x].push_back(i);
            conv[i].push_back(x);
        }
    }

    queue <pii> q;
    q.push({1,1});
    visited[1]= 1;
    int ans =-1;

    while (!q.empty()){
        pii node = q.front(); q.pop();
        if (node.first == n){
            ans = node.second;
            break;
        }
        for (int g : groups[node.first]){
            for (int nxt : conv[g]){
                if (!visited[nxt]){
                    visited[nxt] = 1;
                    q.push({nxt, node.second+1});
                }
            }
        }
    }
    cout << ans << "\n";

}