#include <bits/stdc++.h>
using namespace std;

int rows[35], test[35];
unordered_set <int> pos;
int R, C;

void flip(int mask){
    test[R-1] = rows[R-1];

    for (int i=R-1; i>=0; i--){
        if (mask & (1 << i)){
            test[i] = rows[i] ^ test[i+1];
        }
        else{
            test[i] = rows[i];
        }
    }
    //cout << mask << " "<< test[0] << "\n";
    pos.insert(test[0]);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> R >> C;
    for (int i=R-1; i>=0; i--){
        for (int k=0; k<C; k++){
            int x; cin >> x;
            if (x){
                rows[i] ^= (1 << k);
            }
        }
    }

    for (int i=0; i<=R-1; i++){
        flip((1 << i) -1);
    }

    cout << pos.size() << "\n";
}