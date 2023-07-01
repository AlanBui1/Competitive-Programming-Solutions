#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 5e5+5;
int rating[MAXSZ], n, q,a, b, rMax[MAXSZ], lMax[MAXSZ];
// vector <int> freq[15];
int freq[15][MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i= 1; i<=n; i++){
        cin >> rating[i];
        for (int k=1; k<=10; k++){
            if (rating[i] == k){
                freq[k][i] = freq[k][i-1]+1;
            }
            else freq[k][i] = freq[k][i-1];
        }

        rMax[i] = max(rating[i], rMax[i-1]);
        // cout << rMax[i] << " ";
    }
    // cout << "\n";
    lMax[n] = rating[n];
    for (int i=n-1; i>0; i--){
        lMax[i] = max(lMax[i+1], rating[i]);
        // cout << lMax[i] << " ";
    }


    while (q--){
        cin >> a >> b;
        int highest = max(rMax[a-1], lMax[b+1]), ans;
        ans = freq[highest][a-1] + freq[highest][n] - freq[highest][b];
        cout << highest << " " << ans << "\n";
    }
}