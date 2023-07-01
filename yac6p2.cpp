#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

int start[MAXSZ], dest[MAXSZ], parent[MAXSZ], height[MAXSZ];
vector <int> graph[MAXSZ];

void dfs(int curNode, int curHeight){
    height[curNode] = curHeight;
    for (int nxt : graph[curNode]){
        dfs(nxt, curHeight+1);
    }
}

int find(int a){
    return parent[a] == a ? a: parent[a] = find(parent[a]);
}


int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int c1, c2;

    for (int i=1; i<=n; i++){
        cin >> start[i];
        if (start[i] == -1) c1 = i;
        else graph[start[i]].push_back(i);
        parent[i] = start[i];
    }

    for (int i=1; i<=n; i++){
        cin >> dest[i];
        if (dest[i] == -1) c2 = i;
    }

    if (c1 != c2){
        cout << "-1\n";
        return 0;
    }

    dfs(c1, 0);
    vector <pair <int, int>> nodes, ans;

    for (int i=1; i<=n; i++){
        nodes.push_back({height[i], i});
    }

    sort(nodes.begin(), nodes.end(), greater <pair<int, int>>());

    for (int i=0; i<n; i++){
        pair <int, int> node = nodes[i];
        int h = node.first, v = node.second;
        //cout << h <<  " " << v << "\n";

        if (start[v] == dest[v]){
            continue;
        }

        int HEAD1 = find(v), HEAD2 = find(dest[v]);
        ans.push_back({v, dest[v]});
    }

    cout << ans.size() << "\n";
    for (pair <int, int> pii : ans){
        cout << pii.first << " " << pii.second << "\n";
    }

}