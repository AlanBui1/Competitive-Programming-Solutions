#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 3e3 + 5;
int m, n, r, c, x, r1, r2, c1, c2;
int board[MAXSZ][MAXSZ], sums[MAXSZ][MAXSZ];

bool isLight (int row, int col){
    return row%2 == col%2;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> m >> n;

    while (true){
        cin >> r >> c >> x;
        if (r == 0 && c == 0 && x == 0) break;
        if (isLight(r, c)) board[r][c] = x;
        else board[r][c] = -x;
    }

    for (int i=1; i<=m; i++){
        for (int k=1; k<=n; k++){
            sums[i][k] = board[i][k] + sums[i][k-1] + sums[i-1][k] - sums[i-1][k-1];
            // cout << sums[i][k] << " ";
        }
        // cout << "\n";
    }

    while (true){
        cin >> r1 >> c1 >> r2 >> c2;
        if (r1 == c1 && r2 == r1 && c2 == r1 && r1 == 0){
            break;
        }

        int ans = sums[r2][c2] - sums[r2][c1-1] - sums[r1-1][c2] + sums[r1-1][c1-1];
        // cout << sums[r1-1][c1];
        // cout << sums[1][3];
        if (isLight(r1, c1)) cout << ans << "\n";
        else cout << ans* (-1) << "\n";
    }
}