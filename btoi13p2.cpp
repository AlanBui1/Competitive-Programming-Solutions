#include <bits/stdc++.h>
using namespace std;

string a, b;
long long c;
int len;

long long dp[2][20][12][12];

long long solve(int index, bool flag, int prev, int prev2, bool added, string s){

    if (index == len){
        return 1;
    }

    if (dp[flag][index][prev][prev2] != -1){
        return dp[flag][index][prev][prev2];
    }

    int highest = 9;
    if (flag){
        highest = s[index]-'0';
    }

    long long ret= 0;
    bool ns;
    for (int i=0; i<=highest; i++){
        if (i < s[index]-'0'){
            ns = 0;
        }
        else{
            ns = flag;
        }

        if (!added && i == 0){
            ret += solve(index+1, ns, -1, -1, 0, s);
        }
        else{
            if (i != prev && i != prev2){
                ret += solve(index+1, ns, i, prev, 1, s);
            }
        }
    }
    dp[flag][index][prev][prev2] =ret;
    return ret;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> c >> b;

    memset(dp, -1, sizeof(dp));
    len = b.length();
    long long ans = solve(0,1,-1,-1,0,b);

    memset(dp, -1, sizeof(dp));
    a = to_string(c-1);
    len = a.length();
    ans -= solve(0,1,-1,-1,0,a);

    cout << ans<< "\n";

}