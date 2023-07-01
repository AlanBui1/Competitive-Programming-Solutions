#include <bits/stdc++.h>
using namespace std;
const int nax=1e6+5;
const int naxx=1005;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second

vector <pair <int, int>> graph[nax];
int grid[naxx][naxx];
bool visited[naxx][naxx];

int main() {
    int n, m; scan(m); scan(n);

    for (int i=1; i<=m; i++){
        for (int k=1; k<=n; k++){
            cin >> grid[i][k];
            graph[grid[i][k]].push_back({i, k});
        }
    }

    queue <pair <int, int>> q;
    q.push({m, n});

    pair <int, int> node;
    int nx, ny;

    while (!q.empty()){
        node = q.front(); q.pop();
        nx = node.f; ny = node.s;

        visited[nx][ny] = true;
        if (nx == 1 && ny == 1){
            cout << "yes\n";
            return 0;
        }

        for (pair <int,int> nxt : graph[nx*ny]){
            if (!visited[nxt.f][nxt.s]){
                q.push({nxt.f, nxt.s});
            }
        }
        
    }
    cout << "no\n";
}