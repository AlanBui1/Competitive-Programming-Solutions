#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 505;

int n, m, sx, sy;

char grid[MAXSZ][MAXSZ];

struct Move{
    int VX, VY;
    string dir;
}moves[4];

int time(int x, int y, int VX, int VY, int curDist){
    if (curDist > m*n or x < 0 or x >= n or y < 0 or y >= m){
        return curDist;
    }

    if (grid[x][y] == '\\'){
        swap(VX, VY);
    }
    else if (grid[x][y] == '/'){
        swap(VX, VY);
        VX = -VX;
        VY = -VY;
    }
    else if (grid[x][y] == 'C') return curDist;
    return time(x+VX, y+VY, VX, VY, curDist+1);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            cin >> grid[i][k];
        }
    }

    moves[0].dir = "U"; moves[0].VX = -1; moves[0].VY = 0;
    moves[1].dir = "D"; moves[1].VX = 1; moves[1].VY = 0;
    moves[2].dir = "R"; moves[2].VY = 0; moves[2].VY = 1;
    moves[3].dir = "L"; moves[3].VY = 0; moves[3].VY =-1;


    cin >> sx >> sy; sx--; sy--;

    int bestTime = 0;
    string ans = "";

    for (int i=0; i<4; i++){
        int T = time(sx, sy, moves[i].VX, moves[i].VY, 0);

        if (T > bestTime){
            bestTime = T;
            ans = moves[i].dir;
        }
    }

    cout << ans << "\n";
    if (bestTime > m*n){
        cout << "Voyager\n";
        return 0;
    }
    cout << bestTime << "\n";
}