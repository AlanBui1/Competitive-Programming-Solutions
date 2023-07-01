#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 105;
const int MOD = 1000003;

int dp[MAXSZ][MAXSZ][MAXSZ];
char grid[MAXSZ][MAXSZ];
int lives[MAXSZ][MAXSZ], n;

int val(char c){
    if (c == 'P'){
        return 10000000;
    }
    int v = c-'0';
    if (0 <= v && v <= 9){
        return v;
    }
    return 0;
}

int recur(int x, int y, int life){
    if (x < 1 || x > n || y < 1 || y > n){
        return 0;
    }
    if (life <= 0){
        return 0;
    }

    if (x == n && y == n){
        return 1;
    }

    if (dp[x][y][life] != -1){
        return dp[x][y][life];
    }

    int ret = 0;

    ret += recur(x+1, y, life - lives[x+1][y]);
    ret %= MOD;
    ret += recur(x, y+1, life - lives[x][y+1]);
    ret %= MOD;
    dp[x][y][life] = ret;
    return ret%MOD;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int l;
    cin >> l >> n;

    for (int i=1; i<=n; i++){
        for (int k=1; k<=n; k++){
            char c; cin >> c;
            grid[i][k]= c;
            lives[i][k] = val(c);
        }
    }

    for (int i=0; i<MAXSZ; i++){
        for (int k=0; k<MAXSZ; k++){
            for (int j=0; j<MAXSZ; j++){
                dp[i][k][j] = -1;
            }
        }
    }

    cout << recur(1, 1, l) << "\n";

}