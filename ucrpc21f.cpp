#include <bits/stdc++.h>
using namespace std;
const int nax = 1005;
const int inf = 1e9;

char grid[nax][nax];
int dist[nax][nax];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;

    string line;
    for (int i=0; i<n; i++){
        cin >> line;
        for (int k=0; k<n; k++){
            grid[i][k] = line[k];
            dist[i][k]  =inf;
        }
    }
    
    dist[0][0] = t*(grid[0][0] == 'b');

    // queue <pair <int, int>> q;
    priority_queue <pair <int, pair <int, int>>, vector <pair <int, pair <int, int>>>, greater <pair <int, pair <int, int>>>> q;
    q.push({dist[0][0],{0, 0}});
    pair <int, pair <int, int >> node;
    int curX, curY, curDist;

    while (!q.empty()){
        node = q.top(); q.pop();

        curDist = node.first; curX = node.second.first; curY = node.second.second;

        if (curX - 1 >= 0){
            if (dist[curX-1][curY] > dist[curX][curY]+ 1+(t*(grid[curX-1][curY] == 'b'))){
                dist[curX-1][curY] = dist[curX][curY]+ 1+(t*(grid[curX-1][curY] == 'b'));
                q.push({dist[curX-1][curY],{curX-1, curY}});
            }
        }

        if (curX+1 < n){
            if (dist[curX+1][curY] > dist[curX][curY]+1+(t*(grid[curX+1][curY] == 'b'))){
                dist[curX+1][curY] = dist[curX][curY]+1+(t*(grid[curX+1][curY] == 'b'));
                q.push({dist[curX+1][curY],{curX+1, curY}});
            }
        }

        if (curY - 1 >= 0){
            if (dist[curX][curY-1] > dist[curX][curY]+ 1+(t*(grid[curX][curY-1] == 'b'))){
                dist[curX][curY-1] = dist[curX][curY]+ 1+(t*(grid[curX][curY-1] == 'b'));
                q.push({dist[curX][curY-1],{curX, curY-1}});
            }
        }

        if (curY+1 < n){
            if (dist[curX][curY+1] > dist[curX][curY]+1+(t*(grid[curX][curY+1] == 'b'))){
                dist[curX][curY+1] = dist[curX][curY]+1+(t*(grid[curX][curY+1] == 'b'));
                q.push({dist[curX][curY+1],{curX, curY+1}});
            }
        }

    }

    cout << dist[n-1][n-1] << "\n";

}