#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=105;

int arr[MAXSZ][MAXSZ];
char grid[MAXSZ][MAXSZ];

int sum(int x1, int y1, int x2, int y2){
    return arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int r, s, k; cin >> r >> s >> k;

    for (int i=1; i<=r; i++){
        for (int j=1; j<=s; j++){
            cin >> grid[i][j];
            if (grid[i][j] == '*'){
                arr[i][j]++;
            }
        }
    }

    for (int i=1; i<=r; i++){
        for (int j=1; j<=s; j++){
            arr[i][j] += arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }

    int best =0;
    int x, y;
    k--;
    for (int i=1; i<=r-k; i++){
        for (int j=1; j<=s-k; j++){
            int val = sum(i, j, i+k, j+k) - sum(i, j, i+k, j) - sum(i, j, i, j+k) - sum(i+k, j, i+k, j+k) - sum(i, k+j,i+k, j+k);
            val += sum(i, j, i, j) + sum(i+k, j, i+k, j) + sum(i, j+k, i, j+k) + sum(i+k, j+k, i+k, j+k);
            if (val > best){
                best = val;
                x = i; y = j;
            }
        }

    }

    for (int i=0; i<=k; i++){
        grid[x][i+y] = '-';
        grid[x+k][i+y] = '-';
        grid[x+i][y] = '|';
        grid[x+i][y+k] = '|';
    }

    grid[x][y] = '+';
    grid[x+k][y] = '+';
    grid[x][y+k] = '+';
    grid[x+k][y+k] = '+';

    cout << best << "\n";

    for (int i=1; i<=r; i++){
        for (int j=1; j<=s; j++){
            cout << grid[i][j];
        }
        cout << "\n";
    }




}