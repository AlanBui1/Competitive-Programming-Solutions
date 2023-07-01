#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=505;

bool visited[MAXSZ];
vector <int> graph[MAXSZ];

struct node{
    int X, Y, R;
};

bool bfs(int start, int dest){
    queue <int> q;
    q.push(start);
    memset(visited, 0, sizeof(visited));

    while (!q.empty()){
        int curNode = q.front(); q.pop();

        if (curNode == dest){
            return true;
        }

        visited[curNode] = true;

        for (int nxt : graph[curNode]){
            if (!visited[nxt]){
                visited[nxt] = true;
                q.push(nxt);
            }
        }
    }
    return false;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0); 

    int b, q; cin >> b >> q;
    int x, y, r;

    vector <node> lis;

    for (int i=0; i<b; i++){

        cin >> x >> y >> r;

        for (int k=0; k<i; k++){
            int dist = (abs(lis[k].X-x)*abs(lis[k].X-x)) + (abs(lis[k].Y-y)*abs(lis[k].Y-y));

            if (dist <= r*r){
                graph[i].push_back(k);
                
            }
            if (dist <= lis[k].R*lis[k].R){
                graph[k].push_back(i);
                
            }
        }

        node n;
        n.Y = y; n.R = r; n.X = x;
        lis.push_back(n);
    }
    int a, c;
    while (q--){
        cin >> a >> c; a--; c--;

        if (bfs(a, c)){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }

}