#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=105;
const int INF=1e9;
int moves(string s1, string s2){
    int l1 = s1.length(), l2 = s2.length();
    int dp[MAXSZ][MAXSZ];
    dp[0][0] = 0;


    for (int i=0; i<l1+1; i++){
        for (int k=0; k<l2+1; k++){
            if (i==0 && k==0) continue;

            int repCost = INF, delCost = INF, addCost = INF;

            if (i>0){
                delCost = dp[i-1][k]+1;
            }

            if (k>0){
                addCost = dp[i][k-1]+1;
            }

            if (i>0 && k>0){
                if (s1[i-1] == s2[k-1]){
                    repCost = dp[i-1][k-1];
                }
                else{
                    repCost = dp[i-1][k-1]+1;
                }
            }

            dp[i][k] = min(repCost, min(delCost, addCost));
        }
    }


    return dp[l1][l2];
}

int main() {

    cin.sync_with_stdio(0); cin.tie(0);

    string MAINSTRING; cin >> MAINSTRING;

    int n; cin >> n;
    double ans=INF;
    while (n--){
        double t; cin >> t;
        double tot=0;
        for (int i=0; i<t; i++){
            string word; cin >> word;
            tot += moves(MAINSTRING, word);
        }
        ans = min(ans, tot/t);
        
    }
    cout << setprecision(7) << ans << "\n";



}