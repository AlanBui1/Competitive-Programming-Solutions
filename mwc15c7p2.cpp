#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;

int arr[10][MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    
    int f, r; cin >> f >> r;
    
    for (int i=1; i<=f; i++){
        for (int k=1; k<=r; k++){
            cin >> arr[i][k];
        }
    }
    
    for (int i=1; i<=f; i++){
        for (int k=1; k<MAXSZ; k++){
            arr[i][k] +=arr[i][k-1];
        }
    }
    int q; cin >> q;
    
    while (q--){
        int a, b, c; cin >> a >> b >> c;
        
        cout << arr[c][b] - arr[c][a-1] << "\n";
    }
}