#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=3001;

int dp[MAXSZ][MAXSZ];
int main() {
    string str1, str2;

    cin >> str1 >> str2;

    int len1 = str1.length();
    int len2 = str2.length();

    for (int i=1; i<= len1; i++){
        for (int k=1; k<= len2; k++){
            dp[i][k] = max(dp[i][k], max(dp[i-1][k], dp[i][k-1]));

            if (str1[i-1] == str2[k-1]){
                dp[i][k] = dp[i-1][k-1]+1;
            }
            
        }
    }

    string ans = "";
    int Lval, Uval, curVal;

    while (len1 != 0 && len2 != 0){
        Lval = dp[len1][len2-1];
        Uval = dp[len1-1][len2];
        curVal = dp[len1][len2];

        if (Lval == curVal){
            len2--;
        }
        else if (Uval == curVal){
            len1--;
        }
        else{
            ans = ans+str1[len1-1];
            len1--; len2--;
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    
}