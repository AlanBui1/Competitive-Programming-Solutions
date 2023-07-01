#include <bits/stdc++.h>
using namespace std;
const int SQRT = 500;
const int MAXSZ=2e5+5;
#define ll long long

ll b(int i){
    return i/SQRT;
}

ll s(int i){
    return i%SQRT;
}

struct node{
    ll block, spot, cost;
    bool done;
};

ll arr[MAXSZ], n, q, x, v, oper;
node blocks[SQRT][SQRT];

void pushUp(ll bl, ll sp, ll ind){
    if (b(ind) == b(ind+arr[ind])){
        blocks[bl][sp] = blocks[b(ind+arr[ind])][s(ind+arr[ind])];
        blocks[bl][sp].cost += 1;
    }
    else{
        blocks[bl][sp].block = b(ind+arr[ind]);
        blocks[bl][sp].spot = s(ind+arr[ind]);
        blocks[bl][sp].done = (ind+arr[ind] >= n);
        blocks[bl][sp].cost = 1;

    }  
}

ll query(ll ind){
    ll tot = 0;
    while (!blocks[b(ind)][s(ind)].done){
        tot += blocks[b(ind)][s(ind)].cost;
        ind = blocks[b(ind)][s(ind)].block*SQRT+blocks[b(ind)][s(ind)].spot;
    }
    return tot+blocks[b(ind)][s(ind)].cost;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    for (int i=n-1; i>=0; i--){
        if (i+arr[i] >= n){
            blocks[b(i)][s(i)].block = b(n); 
            blocks[b(i)][s(i)].spot = 0;
            blocks[b(i)][s(i)].cost = 1;
            blocks[b(i)][s(i)].done = 1;
        }
        else{
            pushUp(b(i), s(i), i);
        }
    }

    cin >> q;
    while (q--){
        cin >> oper;
        if (oper == 1){
            cin >> x;
            cout << query(x) << "\n";
        }
        else{
            cin >> x >> v;
            arr[x] = v;
            for (int i=s(x); i >=0; i--){
                pushUp(b(x), i, b(x)*SQRT+i);
            }
            
        }
    }

    // for (int i=0; i<n; i++){
    //     cout << blocks[b(i)][s(i)].block << " " <<blocks[b(i)][s(i)].spot << " " << blocks[b(i)][s(i)].cost<< " " << blocks[b(i)][s(i)].done << "\n";
    // }
}