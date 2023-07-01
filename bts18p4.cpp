#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXSZ = 1e5+5;

int y[MAXSZ], length, endpoint;
bool works[MAXSZ], visited[MAXSZ];
vector <int> graph[MAXSZ];

bool roots(int x){
    int lo = 0, hi = 1e8;

    while (lo <= hi){
        int mid = (lo+hi)/2;

        int val = mid*(mid+1);

        if (val == x) return true;

        if (val < x) lo  = mid+1;
        else hi = mid-1;
    }
    return false;
}

void dfs(int curNode, int prevNode, int curDist){
    visited[curNode] = 1;
    if (!works[curNode])return;

    if (curDist > length){
        length= curDist;
        endpoint = curNode;
    }

    for (int nxtNode : graph[curNode]){
        if (nxtNode == prevNode || !works[nxtNode]){
            continue;
        }
        dfs(nxtNode, curNode, curDist+1);
    }
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    bool found = 0;
    for (int i=1; i<=n; i++){
        cin >> y[i];
        if (roots(y[i])){
            works[i] = 1;
            found = 1;
        }
    }

    for (int i=0; i<n-1; i++){
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int ans = 0;

    for (int i=1; i<=n; i++){
        if (works[i] && !visited[i]){
            endpoint = -1;
            length = -1;
            dfs(i, i, 0);
            dfs(endpoint, endpoint, 0);
            ans = max(ans, length);
        }
    }

    if (found){
        cout << max(ans+1, 1ll) << "\n";
    }
    else cout << 0 << "\n";
}