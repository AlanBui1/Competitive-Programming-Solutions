#include <bits/stdc++.h>
using namespace std;
const int MAXK = 1 << 19;
#define f first
#define s second


vector <pair <int, int>> graph[19];

int n, m;
int dp[20][MAXK];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    int a,b, l;

    for (int i=0; i<m; i++){
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
    }

    priority_queue <pair <pair <int, int>, int>> q;
    q.push({{0, 0},1});

    pair <pair<int, int>, int> node;
    
    int ans = -1;
    int curNode, curDist, mask;

    while (!q.empty()){
        node = q.top(); q.pop();
        curNode = node.f.s; curDist = node.f.f; mask = node.s;

        if (curNode == n-1) {
            ans = max(ans, curDist);
            continue;
        }

        for (pair <int, int> nxt : graph[curNode]){
            if (! (mask & (1<<nxt.f))){
                if (dp[nxt.f][mask | (1<<nxt.f)] < curDist+nxt.s){
                    dp[nxt.f][mask | (1<<nxt.f)] = max(dp[nxt.f][mask | (1<<nxt.f)], curDist+nxt.s);
                    q.push({{curDist+nxt.s,nxt.f}, mask | (1<<nxt.f)});
                }
            }
            
        }
    }

    
    cout << ans << "\n";
}