#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    
    int ans = 0;
    
    for (int i=1; i*i <= n; i++){
        if (n%i == 0){
            ans += i; ans += n/i;
            if (i == n/i) ans  -= i;
        }
    }
    cout << ans << "\n";
    return 0;
}