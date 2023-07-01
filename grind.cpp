#include <bits/stdc++.h>
using namespace std;

const int nax = 1e7+5;

int arr[nax];

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int n; cin >> n;

    for (int i=0; i<n; i++){
        int s, f; cin >> s >> f;

        arr[s]++; arr[f]--;
    }

    int ans = 0;
    for (int i=1; i<nax; i++){
        arr[i] += arr[i-1];
        ans = max(ans, arr[i]);
    }
    cout << ans << "\n";
}