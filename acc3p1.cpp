#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nax =1e6+5;

int freq[nax], arr[nax];

int32_t main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;

    for (int i=0; i<n; i++) cin >> arr[i];

    int p1 = 0, p2 = 0;
    int cnt = 1;
    int ans = 0;
    freq[arr[p1]] ++;

    while (p1 < n && p2 < n){
        if (cnt >= k){
            ans += n-p2;
            freq[arr[p1]]--;
            if (freq[arr[p1]] == 0){
                cnt--;
            }
            p1++;
        }
        else{
            p2++;
            if (p2 >= n) break;

            freq[arr[p2]]++;
            if (freq[arr[p2]] == 1){
                cnt++;
            }
        }
    }
    cout << ans << "\n";
}