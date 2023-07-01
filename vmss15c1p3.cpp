#include <bits/stdc++.h>
using namespace std;

#define int double

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int sx, sy, ex, ey;

    cin >> sx >> sy >> ex >> ey;

    int A = -(ey-sy), B = ex-sx;

    int C = -((A*sx) + (B*sy));

    int n;
    int32_t ans = 0; cin >> n;

    for (int i=0; i<n; i++){
        int a, b, c; cin >> a >> b >> c;


        if (A*b - a*B == 0) continue;

        double px = (double)((B*c) - (b*C))/(double)((A*b) - (a*B));
        double py = (double)((C*a) - (c*A))/(double)((A*b) - (a*B));
        //cout << px << " "  << py << "\n";
        if (min(sx, ex) < px && px < max(sx, ex) && min(sy, ey) < py && py < max(sy, ey)){
            ans++;
        }
    }
    //cout << A << " " << B << " " << C << "\n";

    cout << ans << "\n";
}