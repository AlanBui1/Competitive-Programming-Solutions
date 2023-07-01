#include <bits/stdc++.h>
using namespace std;
const int nax = (1<<13)+5;
#define ll long long
int bit[nax][nax], arr[nax];

ll sum(int x, int y){
    ll s = 0;
    for (int i=x; i>0; i-=(i&-i)){
        for (int k=y; k>0; k -= (k&-k)){
            s += bit[i][k];
        }
    }
    return s;
}

void update(int x, int y, int u){
    for (int i=x; i<nax; i+=(i&-i)){
        for (int k=y; k<nax; k+=(k&-k)){
            bit[i][k] += u;
        }
    }
}

ll query(int x1, int x2, int y1, int y2){
    return sum(x2, y2)-sum(x2, y1-1)-sum(x1-1, y2)+sum(x1-1, y1-1);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int z, n, q; cin >> n;

    for (int i=1; i<=n; i++){
        cin >> z;z++;
        update(i,z,1);
        arr[i] = z;
    }
    cin >> q;
    int oper, i, j, a, b, h;
    while (q--){
        cin >> oper;
        if (oper == 2){
            cin >> i >> h;
            h++;
            update(i+1, arr[i+1], -1);
            update(i+1, h, 1);
            arr[i+1] = h;
        }
        else{
            cin >> i >> j >> a >> b;
            cout << query(i+1, j+1, a+1, b+1) << "\n";
        }
    }
}