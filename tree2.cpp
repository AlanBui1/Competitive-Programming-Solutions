#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
const int inf= 1e9;
#define f first
#define s second
pii moves[4] = {{0,1}, {0,-1}, {1, 0}, {-1, 0}};
struct tree{
    int height, cost, num;
}grid[15][15];
int r, c;
pii start;

bool legal(int x, int y){
    return 0 <= x && x < r && 0 <= y && y < c;
}

int dist(int x, int y){
    return ((start.f-x)*(start.f-x)) + ((start.s-y)*(start.s-y));
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> r >> c;
    char x;
    
    for (int i=0; i<r; i++){
        for (int k=0; k<c; k++){
            grid[i][k].cost = 1e9;
            grid[i][k].num = 1e9;
            cin >> x;
            if (x == '.'){
                grid[i][k].height = 0;
                continue;
            }
            if (x == 'X') start = {i, k};
            else{
                grid[i][k].height = x-'0';
            }
        }
    }
    queue <pair <pii, pii>> q; //{{curX, curY}, {curCost, curNum}}
    q.push({start, {0,0}});

    grid[start.f][start.s].cost = 0;
    grid[start.f][start.s].num = 0;
    grid[start.f][start.s].height = 0;

    while (!q.empty()){
        auto node = q.front();q.pop();
        int curX = node.f.f, curY = node.f.s, curCost = node.s.f, curNum = node.s.s;

        if (grid[curX][curY].num < curNum) continue;

        for (pii move : moves){
            if (legal(curX+move.f, curY+move.s)){
                if (grid[curX+move.f][curY+move.s].cost > curCost+grid[curX+move.f][curY+move.s].height){
                    grid[curX+move.f][curY+move.s].num = curNum+(grid[curX+move.f][curY+move.s].height > 0);
                    grid[curX+move.f][curY+move.s].cost = curCost + grid[curX+move.f][curY+move.s].height;
                    q.push({{curX+move.f, curY+move.s}, {grid[curX+move.f][curY+move.s].cost,grid[curX+move.f][curY+move.s].num}});
                }
                else if (grid[curX+move.f][curY+move.s].cost == curCost+grid[curX+move.f][curY+move.s].height){
                    if (grid[curX+move.f][curY+move.s].num > curNum + grid[curX+move.f][curY+move.s].height+(grid[curX+move.f][curY+move.s].height > 0)){
                        grid[curX+move.f][curY+move.s].num = curNum+(grid[curX+move.f][curY+move.s].height > 0);
                        q.push({{curX+move.f, curY+move.s}, {grid[curX+move.f][curY+move.s].cost,grid[curX+move.f][curY+move.s].num}});
                    }
                }
            }
        }
    }

    int maxHeight = -1, ansX=-1, ansY = -1, ansCost = inf, ansNum = inf;

    for (int i=0; i<r; i++){
        for (int k=0; k<c; k++){
            if (grid[i][k].height > maxHeight){
                maxHeight= grid[i][k].height;
                ansX = i;
                ansY = k;
                ansCost = grid[i][k].cost;
                ansNum = grid[i][k].num;
            }
            else if (grid[i][k].height == maxHeight){
                if (dist(i, k) < dist(ansX, ansY)){
                    ansX = i;
                    ansY = k;
                    ansCost = grid[i][k].cost;
                    ansNum = grid[i][k].num;
                }
            }
        }
    }
    cout << ansNum-1 << "\n";
}