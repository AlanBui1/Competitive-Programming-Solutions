#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    long double ans = 0;
    while (n--){
        long double x; cin >> x;
        x -= floor(x/360)*360;
        ans += x;
        ans -= floor(ans/360)*360;
    }
    cout << ans << "\n";
    
    return 0;
}