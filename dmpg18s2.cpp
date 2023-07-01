#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXSZ = 2e5+5;

int arr[MAXSZ], psa[MAXSZ], ans[MAXSZ];

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        psa[i] = psa[i-1]+arr[i];
    }
    int cur = 0;

    for (int i=1; i<=n; i++){
        if (ans[n-i+1]){
            cout << ans[n-i+1] << "\n";
            continue;
        }

        cur += psa[n-i+1]-psa[i-1];

        ans[i] = cur;
        cout << ans[i] << "\n";
    }

}