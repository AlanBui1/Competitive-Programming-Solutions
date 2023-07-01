#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e4+5;

int weight[MAXSZ], cherries[MAXSZ];
int arr[MAXSZ], preweight[MAXSZ];
bool visited[MAXSZ];
vector <pair <int, int>> graph[MAXSZ];

struct node{
    int weigh, cherry;
};

node dfs(int curNode, int curDist, int curCher){

    if (visited[curNode]){
        node ret;
        ret.weigh = weight[curNode];
        ret.cherry = cherries[curNode];
        return ret;
    }

    visited[curNode] = true;

    node ret;
    ret.weigh = curDist; ret.cherry = curCher;
    for (auto nxt : graph[curNode]){
        node child = dfs(nxt.first, nxt.second, arr[nxt.first]);
        ret.weigh += child.weigh;
        ret.cherry += child.cherry;
    }
    
    weight[curNode] = ret.weigh;
    cherries[curNode] = ret.cherry;
    return ret;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, c, k; cin >> n >> c >> k;

    for (int i=0; i<n; i++) cin >> arr[i];

    int a, b, w;
    for (int i=0; i<n-1; i++){
        cin >> a >> b >> w;
        graph[a-1].push_back({b-1, w});
        preweight[b-1] = w;
    }
    int ans = 0;

    for (int i=1; i<n; i++){
        if (visited[i]){
            if (cherries[i] >= c && weight[i] <= k){
                ans++;

            }
        }

        else{
            dfs(i, preweight[i], arr[i]);
            if (cherries[i] >= c && weight[i] <= k){
                ans++;

            }
        }
    }



    cout << ans << "\n";
}