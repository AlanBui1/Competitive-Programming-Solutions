#include <bits/stdc++.h>
using namespace std;
#define pii pair <int, int>
const int MAXSZ = 500;

char grid[MAXSZ][MAXSZ], ans[MAXSZ][MAXSZ];
int r, c, m;

vector <pii> north, east, south, west;

int NDIR = 0, EDIR = 1, SDIR = 2, WDIR = 3;

vector <pii> vel;

string works(int x, int y){
    bool flag = 0;
    for (pii p : north){
        int newX = x + p.first, newY = y + p.second;
        if (newX < 1 || newX > r || newY < 1 || newY > c){
            flag = 1;
            break;
        }
        if (grid[newX][newY] == 'X'){
            flag = 1;
            break;
        }
    }

    if (!flag){
        return "NORTH";
    }

    flag = 0;
    for (pii p : west){
        int newX = x + p.first, newY = y + p.second;
        if (newX < 1 || newX > r || newY < 1 || newY > c){
            flag = 1;
            break;
        }
        if (grid[newX][newY] == 'X'){
            flag = 1;
            break;
        }
    }

    if (!flag){
        return "WEST";
    }

    flag = 0;
    for (pii p : east){
        int newX = x + p.first, newY = y + p.second;
        if (newX < 1 || newX > r || newY < 1 || newY > c){
            flag = 1;
            break;
        }
        if (grid[newX][newY] == 'X'){
            flag = 1;
            break;
        }
    }

    if (!flag){
        return "EAST";
    }

    flag = 0;
    for (pii p : south){
        int newX = x + p.first, newY = y + p.second;
        if (newX < 1 || newX > r || newY < 1 || newY > c){
            flag = 1;
            break;
        }
        if (grid[newX][newY] == 'X'){
            flag = 1;
            break;
        }
    }

    if (!flag){
        return "SOUTH";
    }
    return "FAIL";
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    vel.push_back({-1, 0});
    vel.push_back({0, 1});
    vel.push_back({1, 0});
    vel.push_back({0, -1});

    cin >> r >> c;
    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            cin >> grid[i][k];
        }
    }
    north.push_back({0,0});
    east.push_back({0,0});
    south.push_back({0,0});
    west.push_back({0,0});

    int nx = 0, ny = 0, ex = 0, ey = 0, sx = 0, sy = 0, wx = 0, wy = 0;

    cin >> m;
    for (int i=0; i<m; i++){
        char C; cin >> C;

        if (C == 'F'){
            nx += vel[NDIR].first;
            ny += vel[NDIR].second;
            sx += vel[SDIR].first;
            sy += vel[SDIR].second;
            ex += vel[EDIR].first;
            ey += vel[EDIR].second;
            wx += vel[WDIR].first;
            wy += vel[WDIR].second;

            north.push_back({nx, ny});
            east.push_back({ex, ey});
            west.push_back({wx, wy});
            south.push_back({sx, sy});
        }

        else if (C == 'R'){
            NDIR = (NDIR + 1) % 4;
            EDIR = (EDIR + 1) % 4;
            WDIR = (WDIR + 1) % 4;
            SDIR = (SDIR + 1) % 4;
        }

        else{
            NDIR = (NDIR + 3) % 4;
            EDIR = (EDIR + 3) % 4;
            WDIR = (WDIR + 3) % 4;
            SDIR = (SDIR + 3) % 4;
        }
    }

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            string s = works(i, k);
            if (s != "FAIL"){
                if (s == "NORTH"){
                    ans[i + north[north.size() - 1].first][k + north[north.size() - 1].second] = '*';
                }
                if (s == "EAST"){
                    ans[i + east[east.size() - 1].first][k + east[east.size() - 1].second] = '*';
                }
                if (s == "SOUTH"){
                    ans[i + south[south.size() - 1].first][k + south[south.size() - 1].second] = '*';
                }
                if (s == "WEST"){
                    ans[i + west[west.size() - 1].first][k + west[west.size() - 1].second] = '*';
                }
            }

        }
    }

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            if (ans[i][k] == '*')cout << ans[i][k];
            else cout << grid[i][k];
        }
        cout << "\n";
    }
}