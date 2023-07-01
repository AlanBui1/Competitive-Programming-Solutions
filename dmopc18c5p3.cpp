#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
#define ull unsigned long long

ull n, m, arr[MAXSZ]; 
ull p1, p2;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        arr[i] += arr[i-1];

    }
    ull ans = 0;

    while (p1 <= n && p2 <= n){
        if (arr[p2] - arr[p1] < m){
            ans = max(ans, p2-p1);
            p2++;

        }
        else{
            p1++;
        }
    }    
    cout << ans << "\n";
}