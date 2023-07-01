#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXSZ=1e5+5;

int i, n, j, xi, xf, k;
ll arr[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> i >> n >> j;
    for (int i=0; i<j; i++){
        cin >> xi >> xf >> k;
        arr[xi] += k;
        arr[xf+1] -= k;
    }
    int ans = 0;

    for (int p=1; p<i+1; p++){
        arr[p] += arr[p-1];
        if (arr[p] < n){
            ans ++;

        }

    }

    
    cout << ans << "\n";
}