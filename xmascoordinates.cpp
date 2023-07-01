#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1005;
#define pii pair <int, int> 
#define f first
#define s second
const int inf = 1e9;

char grid[MAXSZ][MAXSZ];
bool visited[MAXSZ][MAXSZ];
int dist[MAXSZ][MAXSZ];

pii present, start, dest;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >>n >> m;

    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            cin >> grid[i][k];

            if (grid[i][k] == 'P'){
                present = {i, k};
            }

            else if (grid[i][k] == 'O'){
                start = {i, k};
            }

            else if (grid[i][k] == 'X'){
                dest = {i, k};
            }

            else if (grid[i][k] == '#'){
                visited[i][k] = 1;
            }
        }
    }
    
    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            dist[i][k] = inf;
        }
    }
    dist[present.f][present.s] = 0;
    queue <pii> q;
    q.push(present);
    while (!q.empty()){
        auto node = q.front(); q.pop();
        int curX = node.f, curY = node.s;
        visited[curX][curY] = 1;

        if (curX+1 < n){
            if (!visited[curX+1][curY]){
                visited[curX+1][curY] = 1;
                dist[curX+1][curY] = dist[curX][curY]+1;
                q.push({curX+1, curY});
            }
        }

        if (curX-1 >= 0){
            if (!visited[curX-1][curY]){
                visited[curX-1][curY] = 1;
                dist[curX-1][curY] = dist[curX][curY]+1;
                q.push({curX-1, curY});
            }
        }

        if (curY+1 < m){
            if (!visited[curX][curY+1]){
                visited[curX][curY+1] = 1;
                dist[curX][curY+1] = dist[curX][curY]+1;
                q.push({curX, curY+1});
            }
        }

        if (curY-1 >= 0){
            if (!visited[curX][curY-1]){
                visited[curX][curY-1] = 1;
                dist[curX][curY-1] = dist[curX][curY]+1;
                q.push({curX, curY-1});
            }
        }
    }

    if (dist[start.f][start.s] == inf || dist[dest.f][dest.s] == inf){
        cout << "-1\n"; 
    }
    else {
        cout << dist[start.f][start.s]+dist[dest.f][dest.s] << "\n";
    }
}