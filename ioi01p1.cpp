#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=1025;

int bit[MAXSZ][MAXSZ];
ll oper, s, x, y, a, l, b, r, t, v;

void update(int UX, int UY, int newVal){
    for (int i=UX; i<=s; i+= i& -i){
        for (int k=UY; k<= s; k+= k&-k){
            bit[i][k] += newVal;
        }
    }
}

ll sum(int X, int Y){
    ll tot=0;
    for (int i=X; i>0; i -= (i & -i)){
        for (int k=Y; k>0; k -= (k & -k)){
            tot += bit[i][k];
        }
    }    

    return tot;
}

ll query(int L, int B, int R, int T){
    return sum(R, T) + sum(L-1, B-1) - sum(L-1, T) - sum(R, B-1); 
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    while (1){
        cin >> oper;

        if (oper == 3){
            return 0;
        }

        if (oper == 0){
            cin >> s;
        }

        if (oper == 1){
            cin >> x >> y >> a;
            x++; y++;
            update(x, y, a);
        }

        if (oper == 2){
            cin >> l >> b >> r >> t;
            l++; b++; r++; t++;
            cout << query(l, b, r, t) << "\n";
        }
    }


}