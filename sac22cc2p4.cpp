#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1005;
const int inf = 1e9;

int dist[MAXSZ][MAXSZ];
char grid[MAXSZ][MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i=0; i<n; i++){
        string line; cin >> line;

        for (int k=0; k<m; k++){
            grid[i][k] = line[k];
            dist[i][k] = inf;
        }
    }

    deque <pair <int, int>> dq;
    dq.push_front({0,0});
    dist[0][0] = (grid[0][0] == 'C');

    while (!dq.empty()){
        pair <int, int> node = dq.front();
        dq.pop_front();

        int curX = node.first, curY = node.second, curDist = dist[curX][curY];

        if (curX+1 < n){
            if (dist[curX+1][curY] > curDist+(grid[curX+1][curY] == 'C')){
                dist[curX+1][curY] = curDist+(grid[curX+1][curY] == 'C');
                if (grid[curX+1][curY] == 'C') dq.push_back({curX+1, curY});
                else dq.push_front({curX+1, curY});
            }
        }

        if (curX -1 >= 0){
            if (dist[curX-1][curY] > curDist+(grid[curX-1][curY] == 'C')){
                dist[curX-1][curY] = curDist+(grid[curX-1][curY] == 'C');
                if (grid[curX-1][curY] == 'C') dq.push_back({curX-1, curY});
                else dq.push_front({curX-1, curY});
            }
        }

        if (curY+1 < m){
            if (dist[curX][curY+1] > curDist+(grid[curX][curY+1] == 'C')){
                dist[curX][curY+1] = curDist+(grid[curX][curY+1] == 'C');
                if (grid[curX][curY+1] == 'C') dq.push_back({curX, curY+1});
                else dq.push_front({curX, curY+1});
            }
        }

        if (curY -1 >= 0){
            if (dist[curX][curY-1] > curDist+(grid[curX][curY-1] == 'C')){
                dist[curX][curY-1] = curDist+(grid[curX][curY-1] == 'C');
                if (grid[curX][curY-1] == 'C') dq.push_back({curX, curY-1});
                else dq.push_front({curX, curY-1});
            }
        }
    }

    cout << dist[n-1][m-1] << "\n";

}