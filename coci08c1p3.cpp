#include <bits/stdc++.h>
using namespace std;

int R, C, psa[105][105], used[105][105];

int sum(int x1, int y1, int x2, int y2){
    return psa[x2][y2] - psa[x2][y1-1]  - psa[x1-1][y2] + psa[x1-1][y1-1];
}

int sum2(int x1, int y1, int x2, int y2){
    return used[x2][y2] - used[x2][y1-1]  - used[x1-1][y2] + used[x1-1][y1-1];
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    int tot = 0;
    for (int i=1; i<=R; i++){
        for (int k=1; k<=C; k++){
            char c; cin >> c;
            psa[i][k] = (c == 'x' ? 1 : 0);
            tot += psa[i][k];
        }
    }

    for (int i=1; i<=R; i++){
        for (int k=1; k<=C; k++){
            psa[i][k] += psa[i][k-1] + psa[i-1][k] - psa[i-1][k-1];
        }
    }
    int x, y, d;
    int found = 0;
    for (int sz = min(R, C); sz > 0; sz--){
        for (int i=1; i<=R-sz+1; i++){
            for (int k=1; k<=C-sz+1; k++){
                if (sum2(i, k, i+sz-1, k+sz-1) == sz*sz){
                    continue;
                }

                if (sum(i, k, i+sz-1, k+sz-1) == sz*sz){
                    if (found == 1){
                        if (tot != sum(i, k, i+sz-1, k+sz-1) - sum2(i, k, i+sz-1, k+sz-1)){
                            continue;
                        }
                    }
                    tot -= sz*sz;
                    found++;
                    cout << i << " " << k << " " << sz << "\n";
                    x =i; y = k; d = sz;
                    for (int a=0; a<sz; a++){
                        for (int b=0; b<sz; b++){
                            used[a+i][b+k] = 1;
                        }
                    }
                    for (int a=1; a<=R; a++){
                        for (int b = 1; b <= C; b++){
                            used[a][b] += used[a][b-1] + used[a-1][b] - used[a-1][b-1];
                        }
                    }
                }
                if (found >= 2) return 0;
            }
        }
    }

    cout << x << " " << y << " " << d << "\n";
}