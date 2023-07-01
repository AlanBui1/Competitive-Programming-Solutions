#include <bits/stdc++.h>
using namespace std;
#define ms(a, b) memset(a, b, sizeof(a))
const int MAXSZ=1e6+5;
const int inf=1e8+5;

int arr1[MAXSZ], arr2[MAXSZ], seq[MAXSZ];

int lis(int n){

    int dp[MAXSZ];
    ms(dp, inf);
    dp[0] = -inf;

    for (int i=0; i<=n; i++){
        int ind = upper_bound(dp, dp+MAXSZ, seq[i])-dp;

        if (seq[i] > dp[ind-1] && seq[i] < dp[ind]){
            dp[ind] = seq[i];
        }
    }

    for (int i=n; i>0; i--){
        if (dp[i] <=n){
            return i;
        }
    }
    return 0;
}


void build(int a[], int b[], int lena, int lenb){

    ms(seq, inf);

    int inds[MAXSZ];
    ms(inds, inf); 

    for (int i=1; i<=lenb; i++){
        inds[b[i]] = i;
    }

    for (int i=1; i<=lena; i++){
        seq[i] = inds[a[i]];
    }

    cout << lis(lenb) << "\n";
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i=1; i<= n; i++){
        cin >> arr1[i];
    }

    int m; cin >> m;
    for (int i=1; i<=m; i++){
        cin >> arr2[i];
    }

    if (m < n){
        build(arr2, arr1, m, n);
    }
    else{
        build(arr1, arr2, n, m);
    }

}