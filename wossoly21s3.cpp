#include <bits/stdc++.h>
using namespace std;
const int nax = 205;
#define pii pair <int, int>

char grid[nax][nax];
pii stops[5];
int dist[nax][nax];
pii graph[130];
pii moves[4] = {{0,-1}, {-1,0}, {1, 0}, {0, 1}};
int r, c;

bool valid(int x, int y, pii m){
    x += m.first; y += m.second;

    if (x < 0 || y < 0 || x >= r || y >= c) return 0;

    if (grid[x][y] == '#' || (0 <= grid[x][y] -'a' && grid[x][y]-'a' <= 26)) return 0;

    return 1;
}

int bfs(int sx, int sy, int ex, int ey){

    int D = 0;
    for (int i=0; i<nax; i++){
        for (int k=0; k<nax; k++){
            dist[i][k] = 1e9;
        }
    }
    dist[sx][sy]= 0;
    queue <pii> q;
    q.push({sx, sy});

    while (!q.empty()){
        auto node = q.front(); q.pop();
        int x =node.first, y = node.second;

        if (0 <= grid[x][y] -'A' && grid[x][y]-'A' <= 26){
            q.push({graph[grid[x][y]-'A'+'A']});
            dist[graph[grid[x][y]-'A'+'A'].first][graph[grid[x][y]-'A'+'A'].second] = dist[x][y];
            continue;
        }

        if (x == ex && y == ey){
            return dist[x][y];
        }
        
        for (pii m : moves){
            if (valid(x, y, m)){
                if (dist[x+m.first][y+m.second] > dist[x][y]+1){
                    dist[x+m.first][y+m.second] = dist[x][y]+1;
                    q.push({x+m.first,y+m.second});
                }
            }
        }

    }

    return dist[ex][ey];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
     cin >> r >> c;

    for (int i=0; i<=r; i++){
        graph[i] = {-1,-1};    
    }

    for (int i=0; i<r; i++){
        for (int k=0; k<c; k++){
            cin >> grid[i][k];
            if (0 <= grid[i][k]-'0' && grid[i][k]-'0' <= 4){
                stops[grid[i][k]-'0'] = {i, k};
            }
            
            else if (0 <= grid[i][k] -'A' && grid[i][k]-'A' <= 26){
                graph[grid[i][k]-'A'+'A'] = {i, k};
            }

            else if (0 <= grid[i][k] -'a' && grid[i][k]-'a' <= 26){
                graph[grid[i][k]-'a'+'a'] = {i, k};
            }
        }
    }

    for (int i=65; i<=91; i++){
        if (graph[i].first != -1){
            swap(graph[i], graph[i+32]);
        }
    }

    int ans = 0;
    for (int i=0; i<4; i++){
        ans += bfs(stops[i].first, stops[i].second, stops[i+1].first, stops[i+1].second);
    }

    if (ans > 1e9){
        cout << -1 << "\n";
    }
    else cout << ans <<"\n";


}