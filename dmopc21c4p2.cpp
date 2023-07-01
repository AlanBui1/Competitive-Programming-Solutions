#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 2e6+5;
const int MAXN = 5e6+5;

int arr[MAXSZ];
bool good[MAXN];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);
    int ans = 0;

    for (int i=0; i<n; i++){
        if (good[arr[i]]) continue;

        ans++;

        for (int k=arr[i]; k < MAXN; k+=arr[i]){
            good[k] = 1;
        }
    }

    cout << ans << "\n";
}