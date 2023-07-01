#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1505;
#define f first
#define s second
int n,m, grid[MAXSZ][MAXSZ];
bool visited[MAXSZ][MAXSZ];

bool isBad(int x, int y, int l){
    if (x+l > n|| y+l > m) return 1;
    return grid[x+l][y+l] - grid[x-1][y+l] - grid[x+l][y-1] + grid[x-1][y-1];
}

bool bfs(int s){

    queue <pair <int, int>> q;
    
    if (isBad(n, m, 0)) return false;   
    if (!isBad(1, 1, s)) q.push({1, 1});

    while (!q.empty()){
        auto node = q.front(); q.pop();

        int x = node.f, y = node.s;

        visited[x][y] = true;

        if (x+s == n && y+s == m) return true;

        if (x+1 <= n){
            if (!visited[x+1][y]){
                if (!isBad(x+1, y, s)){
                    visited[x+1][y] = true;
                    q.push({x+1, y});
                }
            }
        }

        if (x-1>=1){
            if (!visited[x-1][y]){
                if (!isBad(x-1, y, s)){
                    visited[x-1][y] = true;
                    q.push({x-1, y});
                }
            }
        }

        if (y+1 <= m){
            if (!visited[x][y+1]){
                if (!isBad(x, y+1, s)){
                    visited[x][y+1] = true;
                    q.push({x, y+1});
                }
            }
        }

        if (y-1 >= 1){
            if (!visited[x][y-1]){
                if (!isBad(x, y-1, s)){
                    visited[x][y-1] = true;
                    q.push({x, y-1});
                }
            }
        }
    }


    return 0;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    char x;
    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            cin >> x;
            grid[i+1][k+1] = (x == 'X')-grid[i][k]+ grid[i][k+1]+grid[i+1][k];

        }
    }

    int L=0, R=min(n, m), ans = 0;

    while (L <= R){
        for (int i=0; i<=n; i++){
            for (int k=0; k<=m; k++){
                visited[i][k] = false;
            }
        }
        // memset(visited, false, sizeof(visited));
        int mid = (L+R)/2;
        if (bfs(mid-1)){
            ans = max(ans, mid);
            L = mid+1;
        }
        else{
            R = mid-1;
        }
    }
    cout << ans << "\n";
    
}