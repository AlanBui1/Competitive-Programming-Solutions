#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=251;
#define ll long long

ll bit[MAXSZ][MAXSZ][MAXSZ];
int arr[MAXSZ][MAXSZ][MAXSZ];
int n, q;

void update(int X, int Y, int Z, int newVal){
    for (int i=X; i<=n; i+= i& -i){
        for (int k=Y; k<=n; k+= k& -k){
            for (int j = Z; j <= n; j+= j&-j){
                bit[i][k][j] += newVal;
            }
        }
    }
}

ll sum(int X, int Y, int Z){
    ll tot=0;
    for (int i=X; i>0; i -= i & -i){
        for (int k=Y; k>0; k -= k& -k){
            for (int j=Z; j>0; j -= j&-j){
                tot += bit[i][k][j];
            }
        }
    }
    return tot;
}

ll query(int X1, int Y1, int Z1, int X2, int Y2, int Z2){
    return sum(X2, Y2, Z2) - sum(X1-1, Y2, Z2) - sum(X2, Y1-1, Z2) - sum(X2, Y2, Z1-1) - sum(X1-1, Y1-1, Z1-1) + sum(X1-1, Y1-1, Z2) + sum(X1-1, Y2, Z1-1) + sum(X2, Y1-1, Z1-1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    char oper;

    int x, y, z, v, x1, x2, y1, y2, z1, z2;
    ll ans=0;
    while (q--){
        cin >> oper;

        if (oper=='C'){
            cin >> x >> y >> z >> v;

            update(x, y, z, v-arr[x][y][z]);
            arr[x][y][z] = v;
        }

        else{
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ans += query(x1, y1, z1, x2 , y2 , z2);
        }
    }
    cout << ans << "\n";
}