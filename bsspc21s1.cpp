#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e3+5;

char grid[MAXSZ][MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            cin >> grid[i][k];
        }
    }

    bool flag = 0;

    for (int i=0; i<n; i++){
        if (flag) break;
        for (int k=0; k<m; k++){
            if (grid[i][k] != '.'){
                if (grid[n-1-i][k] != grid[i][k]){
                    if (grid[n-1-i][k] == '.') grid[n-1-i][k] = grid[i][k];
                    else{
                        flag = true;
                        break;
                    }
                }

                if (grid[n-1-i][m-1-k] != grid[i][k]){
                    if (grid[n-1-i][m-1-k] == '.') grid[n-1-i][m-1-k] = grid[i][k];
                    else{
                        flag = true;
                        break;
                    }
                }

                if (grid[i][m-1-k] != grid[i][k]){
                    if (grid[i][m-1-k] == '.') grid[i][m-1-k] = grid[i][k];
                    else{
                        flag = true;
                        break;
                    }
                }
            }
        }
    }

    if (flag){
        cout << -1 << "\n";
    }

    else{
        for (int i=0; i<n; i++){
            for (int k=0; k<m; k++){
                if (grid[i][k] == '.'){
                    grid[i][k] = 'a';
                }
                cout << grid[i][k];
            }
            cout << "\n";
        }
    }
}