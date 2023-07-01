#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;
const long long O=0;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    long long arr[MAXSZ];

    for (int i=1; i<n+1; i++) cin >> arr[i];

    long long prev, gmax;

    gmax = max(O, arr[1]);
    prev = max(O, arr[2]);

    for (int i=3; i<=n; i++){
        arr[i] += gmax;
        
        gmax = max(gmax, prev);
        
        prev = arr[i];
    }

    cout << max(O, max(gmax, arr[n])) << "\n";



}