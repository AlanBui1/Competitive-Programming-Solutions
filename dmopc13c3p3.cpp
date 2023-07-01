#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1505;

int n, h;
__int32_t grid[MAXSZ][MAXSZ];
bool visited[MAXSZ][MAXSZ];
string ans = "no";

void dfs(int x, int y){

    if (ans == "yes") return;

    if (x == n && y == n){
        ans = "yes";
        return;
    }

    if (x-1 >= 1){
        if (!visited[x-1][y] && abs(grid[x][y]-grid[x-1][y]) <= h){
            visited[x-1][y]= true;
            dfs(x-1, y);
            // visited[x-1][y]= false;
        }
    }

    if (x+1 <= n){
        if (!visited[x+1][y] && abs(grid[x][y]-grid[x+1][y]) <= h){
            visited[x+1][y]= true;
            dfs(x+1, y);
            // visited[x+1][y]= false;
        }
    }

    if (y-1 >= 1){
        if (!visited[x][y-1] && abs(grid[x][y]-grid[x][y-1]) <= h){
            visited[x][y-1]= true;
            dfs(x, y-1);
            // visited[x][y-1]= false;
        }
    }

    if (y+1 <= n){
        if (!visited[x][y+1] && abs(grid[x][y]-grid[x][y+1]) <= h){
            visited[x][y+1]= true;
            dfs(x, y+1);
            // visited[x][y+1]= false;
        }
    }
    
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n >> h;
    for (int i=1; i <=n; i++){
        for (int k=1; k<=n; k++){
            cin >> grid[i][k];
        }
    }
    visited[1][1]= true;
    dfs(1, 1);
    cout << ans << "\n";
}