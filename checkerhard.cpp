#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 3005;

int m, n, oper, r1, r2, c1, c2, newVal;
int bit[MAXSZ][MAXSZ], arr[MAXSZ][MAXSZ];

bool onLight(int r, int c){
    return (r%2 == c%2);
}

void update(int x, int y, int newVal){
    for (int i=x; i <= m; i += (i & -i)){
        for (int k=y; k <= n; k += (k & -k)){
            bit[i][k] += newVal;
        }
    }
}

int sum(int QR, int QC){
    int ans = 0;
    for (int i = QR; i > 0; i -= i & -i){
        for (int k = QC; k > 0; k-= k & -k){
            ans += bit[i][k];
        }
    }
    return ans;
}

int query(int QR1, int QC1, int QR2, int QC2){

    return sum(QR2, QC2) - sum(QR2, QC1-1) - sum(QR1-1, QC2) + sum(QR1-1, QC1-1);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> m >> n;

    while (true){
        cin >> oper;

        if (oper == 0) break;

        if (oper == 1){
            cin >> r1 >> c1 >> newVal;

            if (!onLight(r1, c1)){
                newVal *= -1;  
            }

            update(r1, c1, newVal-arr[r1][c1]);
            arr[r1][c1] = newVal;
        }

        else if (oper == 2) {
            cin >> r1 >> c1 >> r2 >> c2;
            
            if (!onLight(r1, c1)) cout << query(r1, c1, r2, c2)*(-1) << "\n";   
            else cout << query(r1, c1, r2, c2) << "\n";   
        }
    }
    
}