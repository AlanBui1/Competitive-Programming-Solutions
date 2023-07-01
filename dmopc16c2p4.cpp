#include <bits/stdc++.h>
using namespace std;
#define int long long
int zeroes(int n){
    int ans =0;
    for (int i=5; i<=n; i*=5){
        ans += n/i;
    }
    return ans;
}

int32_t main() {
    int a, b; cin >> a >> b;

    int L = 1, R = 1e10;
    int lower=1e10, higher=-1;

    while (L <= R){
        int mid = (L+R)/2, z = zeroes(mid);

        if (z < a){
            L = mid+1;
        }
        else if (z > b){
            R = mid-1;
        }

        else{
            lower = min(lower, mid);
            R = mid-1;
        }
    }

    L = 1; R = 1e10;

    while (L <= R){
        int mid = (L+R)/2, z = zeroes(mid);

        if (z < a){
            L = mid+1;
        }
        else if (z > b){
            R = mid-1;
        }

        else{
            higher = max(higher, mid);
            L = mid+1;
        }
    }
    cout << max(0ll, higher-lower+1) << "\n";

}