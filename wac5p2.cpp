#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, q, l, e;
const int MAXSZ = 2* 1e5 + 5;
ll arr[MAXSZ];
ll minArr[MAXSZ];
ll maxArr[MAXSZ];


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    
    for (int i=0; i<n; i++){
        cin >> arr[i];

    }
    minArr[n-1] = arr[n-1];
    maxArr[n-1] = arr[n-1];
    for (int i=n-2; i>=0; i--){
        minArr[i] = min(arr[i], minArr[i+1]);
        maxArr[i] = max(arr[i], maxArr[i+1]);
    }
    while (q--){
        cin >> l >> e;
        ll left = 0, right = n-1;
        ll mid = (left+right)/2;
        ll ans=INT_MAX;
        bool found = false;
        // for (int i=0; i<n; i++){
        //     if (abs(minArr[i]-l) <= e && abs(maxArr[i]-l) <= e){
        //         ans = i;
        //         break;
        //     }
        // }
        while (left < right && !found){
            //cout << oldLeft << " " << left << " " << right << "\n";
            if (abs(minArr[mid]-l) <= e && abs(maxArr[mid]-l) <= e){
                ans = mid;
                right = mid;
                mid = (left+right)/2;
                // found = true;
                // ans = mid;
                // for (int k=mid; k>=left; k--){
                    
                //     if (abs(minArr[k]-l) > e || abs(maxArr[k]-l) > e){
                //         break;
                //     }
                //     ans = k;
                    
                // }
            }
            else {
                left = mid+1;
                mid = (left+right)/2;
            }
        }

        if (ans != INT_MAX) cout << n-ans << "\n";
        else if (abs(minArr[n-1]-l) <= e && abs(maxArr[n-1]-l) <= e) cout << "1\n";
        else cout << 0 << "\n";
    }
    // for (int i=0; i<n; i++){
    //     cout << minArr[i] << " " << maxArr[i] << "\n";
    // }
}