#include <bits/stdc++.h>
using namespace std;

int grid[105][75][75];

int score(int cur, int x, int y){
    return grid[cur][x-1][y-1] + grid[cur][x-1][y] + grid[cur][x-1][y+1] + grid[cur][x][y-1] + grid[cur][x][y+1] + grid[cur][x+1][y-1] + grid[cur][x+1][y] + grid[cur][x+1][y+1];
}
int r, c;
int cnt (int cur){
    int ret =0;
    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            ret += grid[cur][i][k];
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> r >> c;

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            char _; cin >> _;

            if (_ == 'X'){
                grid[0][i][k] = 1;
            }
            else{
                grid[0][i][k] = 0;
            }

        }

    }

    for (int i=1; i<=100; i++){
        for (int k=1; k<=r; k++){
            for (int j=1; j<=c; j++){
                int scr = score(i-1, k, j);
                if (!grid[i-1][k][j] && scr == 3){
                    grid[i][k][j] = 1;
                }
                else if (grid[i-1][k][j] && (scr == 2 || scr == 3)){
                    grid[i][k][j] = 1;
                }
                else {
                    grid[i][k][j] = 0;
                }
            }
        }
    }




    cout << cnt(1) << "\n";
    cout << cnt(5) << "\n";
    cout << cnt(10) << "\n";
    cout << cnt(50) << "\n";
    cout << cnt(100) << "\n";
}