#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

int arr[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, k; cin >> n >> k;
    
    for (int i=0; i<k; i++){
        int x; cin >> x;
        arr[x] ++;
    }
    
    for (int i=1; i<MAXSZ; i++){
        arr[i] += arr[i-1];
    }
    
    int q; cin >> q;
    for (int i=0; i<q; i++){
        int a, b; cin >> a >> b;
        
        cout << arr[b] - arr[a-1] << "\n";
    }
}