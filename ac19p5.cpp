#include <bits/stdc++.h>
using namespace std;
const int nax = 1505;

int n;
int grid[nax][nax], dist[nax][nax];
bool visited[nax][nax];

int dfs(int curX, int curY){
    if (visited[curX][curY]) return dist[curX][curY];

    visited[curX][curY] = true;

    int& ret = dist[curX][curY];

    if (curX+1 < n){
        if (grid[curX+1][curY] > grid[curX][curY]){
            ret = max(ret, 1+dfs(curX+1, curY));
        }
    }
    if (curX-1 >= 0){
        if (grid[curX-1][curY] > grid[curX][curY]){
            ret = max(ret, 1+dfs(curX-1, curY));
        }
    }

    if (curY+1 < n){
        if (grid[curX][curY+1] > grid[curX][curY]){
            ret = max(ret, 1+dfs(curX, curY+1));
        }
    }
    if (curY-1 >= 0){
        if (grid[curX][curY-1] > grid[curX][curY]){
            ret = max(ret, 1+dfs(curX, curY-1));
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            cin >> grid[i][k];
        }
    }

    int ans = 0;
    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            if (!visited[i][k]) dfs(i, k);
            ans = max(ans, dist[i][k]);
        }
    }
    cout << ans << "\n";
}