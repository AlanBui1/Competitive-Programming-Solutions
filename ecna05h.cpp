#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1005;
const int inf = -1;
int arr[MAXSZ], dp[MAXSZ][MAXSZ];

int solve(int L, int R, bool g){
    if (L==R) return arr[L];

    if (g){
        if (arr[L] >= arr[R]){
            return arr[L]-solve(L+1, R, 0);
        }
        return arr[R]-solve(L, R-1, 0);
    }

    int& cur = dp[L][R];
    if (cur != -1) return cur;

    cur = max(arr[L]-solve(L+1, R, 1), arr[R]-solve(L, R-1, 1));
    return cur;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n=1;
    int cnt =0;

    while (1){
        cin >> n;
        cnt++;
        if (!n) return 0;

        memset(dp, -1, sizeof(dp));

        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        cout << "In game " << cnt << ", the greedy strategy might lose by as many as " << solve(0, n-1, 0) <<" points."<< "\n";
    }
}