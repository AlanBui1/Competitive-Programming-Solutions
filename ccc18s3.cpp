#include <bits/stdc++.h>
using namespace std;
const int nax = 105;
#define pii pair <int, int>
#define f first
#define s second
const int inf = 1e9;

int dist[nax][nax];
bool bad[nax][nax];
char grid[nax][nax];
int n, m; 
pii start;
pii moves[4] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

bool legal(int x, int y, int mx, int my){
    x += mx; y+=my;

    if (x < 0 || y < 0) return false;
    if (x >= n || y >= m) return false;
    if (bad[x][y]) return false;
    return true;
}

void bfs(){
    queue <pii> q;
    q.push(start);
    
    dist[start.f][start.s] = 0;

    while (!q.empty()){
        pii node = q.front(); q.pop();
        if (bad[node.f][node.s]) continue;
        // cout << node.f << " " << node.s << " "  << grid[node.f][node.s] <<" " << bad[node.f][node.s]<< "\n";
        if (grid[node.f][node.s] == '.' || grid[node.f][node.s] == 'S'){
            for (pii move : moves){
                if (legal(node.f, node.s, move.f, move.s)){
                    if (dist[node.f+move.f][node.s+move.s] > dist[node.f][node.s]+1){
                        dist[node.f+move.f][node.s+move.s] = dist[node.f][node.s]+1;
                        q.push({node.f+move.f, node.s+move.s});
                    }
                }
            }
        }
        else if (grid[node.f][node.s] == 'R'){
            if (legal(node.f, node.s, 0, 1)){
                if (dist[node.f][node.s+1] > dist[node.f][node.s]){
                    dist[node.f][node.s+1] = dist[node.f][node.s];
                    q.push({node.f, node.s+1});
                }
            }
        }
        else if (grid[node.f][node.s] == 'L'){
            if (legal(node.f, node.s, 0, -1)){
                if (dist[node.f][node.s-1] > dist[node.f][node.s]){
                    dist[node.f][node.s-1] = dist[node.f][node.s];
                    q.push({node.f, node.s-1});
                }
            }
        }

        else if (grid[node.f][node.s] == 'U'){
            if (legal(node.f, node.s, -1, 0)){
                if (dist[node.f-1][node.s] > dist[node.f][node.s]){
                    dist[node.f-1][node.s] = dist[node.f][node.s];
                    q.push({node.f-1, node.s});
                }
            }
        }
        else if (grid[node.f][node.s] == 'D'){
            if (legal(node.f, node.s, +1, 0)){
                if (dist[node.f+1][node.s] > dist[node.f][node.s]){
                    dist[node.f+1][node.s] = dist[node.f][node.s];
                    q.push({node.f+1, node.s});
                }
            }
        }
    }
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            cin >> grid[i][k];
            dist[i][k] = inf;
            if (grid[i][k] == 'W'){
                bad[i][k] = 1;
            }
            else if (grid[i][k] == 'S'){
                grid[i][k] = '.';
                start = {i, k};
            }
        }
    }

    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            if (grid[i][k] == 'C'){
                bad[i][k]= 1;

                for (int x = i; x >= 0; x--){
                    if (grid[x][k] == 'W'){
                        break;
                    }
                    if (grid[x][k] == '.'){
                        bad[x][k] = 1;
                    }
                }

                for (int x = i; x < n; x++){
                    if (grid[x][k] == 'W'){
                        break;
                    }
                    if (grid[x][k] == '.'){
                        bad[x][k] = 1;
                    }
                }

                for (int y = k; y >= 0; y--){
                    if (grid[i][y] == 'W'){
                        break;
                    }
                    if (grid[i][y] == '.'){
                        bad[i][y] = 1;
                    }
                }

                for (int y = k; y < m; y++){
                    if (grid[i][y] == 'W'){
                        break;
                    }
                    if (grid[i][y] == '.'){
                        bad[i][y] = 1;
                    }
                }
            }
        }
    }
    grid[start.f][start.s] = 'S';

    bfs();

    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            
            if (grid[i][k] == '.'){
                if (dist[i][k] >= inf){
                    cout << "-1\n";
                }
                else{
                    cout << dist[i][k] << "\n";
                }
            }
        }
    }
}