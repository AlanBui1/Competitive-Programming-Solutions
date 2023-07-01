#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MAXSZ = 405;

ll arr[MAXSZ][MAXSZ], R[MAXSZ][MAXSZ], L[MAXSZ][MAXSZ], ans = 0;


int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=1; i<=n; i++){
        for (int k=1; k<=n; k++){
            cin >> arr[i][k];
            R[i][k] = arr[i][k];
            L[i][k] = arr[i][k];
            R[i][k] += R[i-1][k-1];
            L[i][k] += L[i-1][k+1];
        }
    }
    for (int s=2; s <= n; s++){
        for (int i=1; i<=n; i++){
            for (int k=1; k<=n; k++){
                if (i+s-1 > n || k+s-1 > n) continue;
                if (R[i+s-1][k+s-1] - R[i-1][k-1] - L[i+s-1][k] + L[i-1][k+s] > ans){

                    ans = max(ans, R[i+s-1][k+s-1] - R[i-1][k-1] - L[i+s-1][k] + L[i-1][k+s]);
                }

            }
        }
    }

    cout<< ans << "\n";
}