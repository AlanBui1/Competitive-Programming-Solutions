#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
const int SQRTSZ = 450;

int arr[SQRTSZ][SQRTSZ];
int blocks[SQRTSZ][MAXSZ];

void factorPush(int num, int change, int ind){
    for (int i=1; i<= sqrt(num); i++){
        if (num % i == 0){
            blocks[ind/SQRTSZ][i] += change;
            blocks[ind/SQRTSZ][num/i] += change;
            if (i*i == num) blocks[ind/SQRTSZ][i] -= change;
        }
    }
}

int query(int QL, int QR, int factor){
    int tot = 0;

    if (QL/SQRTSZ == QR/SQRTSZ){
        for (int i=QL%SQRTSZ; i<=QR%SQRTSZ; i++){
            if (arr[QL/SQRTSZ][i] % factor == 0){
                tot++;
            }
        }
    }

    else{
        
        for (int i=QL%SQRTSZ; i<SQRTSZ; i++){
            if (arr[QL/SQRTSZ][i] % factor == 0){
                tot ++;
            }
        }
        for (int i=0; i<= QR%SQRTSZ; i++){
            if (arr[QR/SQRTSZ][i] %factor == 0){
                tot++;
            }
        }
        for (int i=QL/SQRTSZ+1; i<QR/SQRTSZ; i++){
            tot += blocks[i][factor];
        }
    }

    return tot;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for (int i=0; i<n; i++){
        int a; cin >> a;
        arr[i/SQRTSZ][i%SQRTSZ] = a;
        factorPush(a, 1, i);
    }

    int oper, x, l, r, v, u;
    while (q--){
        cin >> oper;

        if (oper == 1){
            cin >> l >> r >> x;
            l--; r--;
            cout << query(l, r, x) << "\n";
        }
        else{
            cin >> u >> v;
            u--;
            factorPush(arr[u/SQRTSZ][u%SQRTSZ], -1, u);
            factorPush(v, 1, u);
            arr[u/SQRTSZ][u%SQRTSZ] = v;
        }
    }    

}