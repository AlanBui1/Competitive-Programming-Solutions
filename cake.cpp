#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ = 5e3+5;

ll n, m, k, q, arr[MAXSZ][MAXSZ];
ll X1, X2, Y1, Y2;
ll A, B, C, D;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> k;

    for (int i=0; i<k; i++){
        cin >> X1 >> Y1 >> X2 >> Y2;
        arr[Y1][X1] ++;
        arr[Y1][X2+1] --;
        arr[Y2+1][X1] --;
        arr[Y2+1][X2+1] ++;
    }

    // cout << "\n";
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            arr[i][j] += arr[i][j-1] + arr[i-1][j];
            arr[i][j] -= arr[i-1][j-1];
            // cout << arr[i][j] << " ";
        }
        // cout << "\n";
    }
    for (int i=1; i<=m; i++){
        for (int j=1; j<=n; j++){
            arr[i][j] += arr[i][j-1] + arr[i-1][j];
            arr[i][j] -= arr[i-1][j-1];
            // cout << arr[i][j] << " ";
        }
        // cout << "\n";
    }

    cin >> q;

    for (int i=0; i<q; i++){
        cin >> A >> B >> C >> D;

        cout << arr[D][C] - arr[D][A-1] - arr[B-1][C] + arr[B-1][A-1] << "\n";
    }
}