#include <bits/stdc++.h>
using namespace std;

#define pii pair <int, int>
#define f first
#define s second

const int nax = 15;

char grid[nax][nax];
int trees;

pii moves[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int _ = 5;
    while (_--){
        trees = 0;
        queue <pair <int, pii>> q;

        for (int i=0; i<10; i++){
            for (int k=0; k<10; k++){
                cin >> grid[i][k];
                if (grid[i][k] == 'T') trees++;
                if (grid[i][k] == 'F'){
                    q.push({0, {i, k}});
                }
            }
        }
        int ans = -1;
        while (!q.empty()){
            auto node = q.front(); q.pop();
            int curTime = node.f;
            int curX = node.s.f, curY = node.s.s;

            for (pii m : moves){
                curX += m.f; curY+=m.s;

                if (0 <= curX && curX < 10 && 0 <= curY && curY < 10){
                    if (grid[curX][curY] == 'T'){
                        grid[curX][curY] = 'F';
                        trees--;
                        q.push({curTime+1, {curX, curY}});

                        if (trees == 0){
                            ans = curTime+1;
                            break;
                        }
                    }
                }

                curX -= m.f; curY-=m.s;
            }
            if (trees == 0){
                break;
            }
        }

        cout << ans << "\n";

        string line; cin >> line;
    }







}