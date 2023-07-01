#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 100;
const int inf = 1e9;
#define f first
#define s second
#define pii pair <int, int>

int tim[MAXSZ][MAXSZ];
char grid[MAXSZ][MAXSZ];

pii moves[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int r, c; cin >> r >> c;

    pii start, dest;

    queue <pair <int, pii>> q;

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            cin >> grid[i][k];
            tim[i][k] = inf;

            if (grid[i][k] == 'D'){
                dest = {i, k};
            }
            else if (grid[i][k] == 'S'){
                start = {i, k};
            }
            else if (grid[i][k] == '*'){
                q.push({0, {i, k}});
                tim[i][k] = 0;
            }
        }
    }

    while (!q.empty()){
        auto node = q.front(); q.pop();
        int curDist = node.f, x = node.s.f, y = node.s.s;

        if (curDist > tim[x][y]) continue;

        for (pii m : moves){
            x+=m.f; y+=m.s;

            if (1 <= x && x <= r && 1 <= y && y <= c){
                if (grid[x][y] == '.'){
                    if (tim[x][y] > curDist+1){
                        tim[x][y] = curDist+1;
                        q.push({curDist+1, {x, y}});
                    }
                }
            }

            x -= m.f; y -= m.s;
        }

    }

    q.push({0, start});

    bitset<MAXSZ> vis[MAXSZ];




    while (!q.empty()){
        auto node = q.front(); q.pop();
        int curDist = node.f, x = node.s.f, y = node.s.s;
        vis[x][y] = 1;

        if (x == dest.f && y == dest.s){
            cout << curDist << "\n";
            return 0;
        }

        for (pii m : moves){
            x+=m.f; y+=m.s;

            if (1 <= x && x <= r && 1 <= y && y <= c){
                if (grid[x][y] != 'X' && tim[x][y] > curDist+1){
                    if (!vis[x][y]){
                        vis[x][y] = 1;
                        q.push({curDist+1, {x, y}});
                    }
                }
            }

            x -= m.f; y -= m.s;
        }
    }

    cout << "KAKTUS\n";


}