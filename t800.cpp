#include <bits/stdc++.h>
using namespace std;

const int nax = 55;
const int inf = 1e9;
#define pii pair <int, int>
#define f first
#define s second

char grid[nax][nax];
int dist[nax][nax][nax+nax];

pii moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int r, c, lim; cin >> r >> c >> lim;

    pii start, dest;

    for (int i=0; i<nax; i++){
        for (int k=0; k<nax; k++){
            for (int j=0; j<nax+nax; j++){
                dist[i][k][j] = inf;
            }
        }
    }

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            cin >> grid[i][k];
            if (grid[i][k] == 'T') start = {i, k};
            if (grid[i][k] == 'E') dest = {i, k};
        }
    }

    dist[start.f][start.s][lim] = 0;

    queue <pair <pii, pii>> q;
    q.push({{0, lim}, start});

    while (!q.empty()){
        auto node = q.front(); q.pop();

        int curDist = node.f.f, curAway = node.f.s, x = node.s.f, y = node.s.s;

        if (grid[x][y] == 'R'){
            curAway = lim;
        }

        if (curAway == 0) continue;

        for (pii m : moves){
            x += m.f; y += m.s;

            if (1 <= x && x <= r && 1 <= y && y <= c){
                if (grid[x][y] != '#'){
                    if (dist[x][y][curAway-1] > curDist+1){
                        dist[x][y][curAway-1] = curDist+1;
                        q.push({{curDist+1, curAway-1}, {x, y}});
                    }
                }
            }


            x -= m.f; y -= m.s;
        }

    }

    int ans = inf;

    for (int i=0; i<nax+nax; i++){
        ans = min(ans, dist[dest.f][dest.s][i]);
    }

    if (ans >= inf){
        cout << "T-800 Terminated.\n";
    }
    else cout << ans << "\n";

}