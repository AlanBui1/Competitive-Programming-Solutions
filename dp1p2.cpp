#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1005;

int arr[MAXSZ];
int dp[MAXSZ][MAXSZ];

int solve(int QL, int QR){
    if (QL == QR) return arr[QL];

    int& cur = dp[QL][QR];
    if (cur != -1) return cur;

    cur = max(arr[QL]-solve(QL+1, QR), arr[QR]-solve(QL, QR-1));
    return cur;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    int tot = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        tot += arr[i];
    } 
    memset(dp, -1, sizeof(dp));
    cout << tot - (-(solve(0, n-1)-tot)/2) << "\n";
}