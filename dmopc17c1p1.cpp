#include <bits/stdc++.h>
using namespace std;

int rows[1005], cols[1005];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int r, c;

    cin >> r >> c;

    char x;
    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            cin >> x;
            if (x == 'X'){
                rows[i]++;
                cols[k]++;
            }  
        }
    }
    int q; cin >> q;
    while (q--){
        int a, b; cin >> a >> b;

        if (rows[b] || cols[a]){
            cout << "Y\n";
        }
        else{
            cout << "N\n";
        }
    }
}