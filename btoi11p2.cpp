#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 205;

bool bad[MAXSZ][MAXSZ];
int ans = 0;
int n, m;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<m; i++){
        int x, y; cin >> x >> y; x--; y--;
        bad[x][y] = 1;
        bad[y][x] = 1;
    }

    for (int i=0; i<n; i++){
        for (int k=i+1; k<n; k++){
            for (int j=k+1; j<n; j++){
                if (!bad[i][j] && !bad[i][k] && !bad[j][k]){
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
}