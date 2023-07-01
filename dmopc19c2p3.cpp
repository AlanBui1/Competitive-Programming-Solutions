#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=3e5+5;

int bit[25][MAXSZ], arr[MAXSZ];;

void update(int x, int y, int c){
    for (int i=x; i<25; i+=(i&-i)){
        for (int k=y; k<MAXSZ; k+=(k&-k)){
            bit[i][k] += c;
        }
    }
}

int sum(int x, int y){
    int s=0;

    for (int i=x; i>0; i-= (i&-i)){
        for (int k=y; k>0; k-= (k&-k)){
            s += bit[i][k];
        }
    }

    return s;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> arr[i]; arr[i]++;
        update(arr[i], i, 1);
    }

    while (m--){
        int oper, a,b, c; cin >> oper;
        if (oper == 1){
            cin >> a >> b; b++;
            update(arr[a], a, -1);
            update(b, a, 1);
            arr[a] = b;
        }
        else{
            cin >> a >> b >> c;
            int cur = 22;

            while (c > 0){
                cur--;
                c -= sum(cur, b) - sum(cur, a-1) - sum(cur-1, b) + sum(cur-1, a-1);
                //cout << c << "\n";
            }
            cout << cur-1 << "\n";
        }
    }

}