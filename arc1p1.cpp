#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 3e3+5;

char grid[MAXSZ][MAXSZ];
int psa[MAXSZ][MAXSZ];

int n, m;

int sum(int x1, int y1, int x2, int y2){
    return psa[x2][y2] - psa[x2][y1-1] - psa[x1-1][y2] + psa[x1-1][y1-1];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int k=1; k<=m; k++){
            cin >> grid[i][k];
            psa[i][k] = (grid[i][k] == '*');
        }
    }

    for (int i=1; i<=n; i++){
        for (int k=1; k<=m; k++){
            psa[i][k] += psa[i-1][k] + psa[i][k-1] - psa[i-1][k-1];
        }
    }
    int ans = 0;
    for (int i=1; i<=n; i++){
        for (int k=1; k<=m; k++){
            if (grid[i][k] == '*')continue;
            if (sum(0, k, i, k) >= 2 || sum(i, 0, i, k) >= 2 || sum(i, k, i, m) >= 2 || sum(i, k, n, k) >= 2) ans++;
        }
    }


    cout << ans << "\n";
}