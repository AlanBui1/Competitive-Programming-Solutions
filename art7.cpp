#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5+5;
const int MOD = 1e9+7;

string s;
int len;
int dp[2][2][2][nax];

int solve(int index, bool one, bool zero, bool flag){
    if (index == len){
        if (one && zero){
            return 1;
        }
        return 0;
    }
    if (dp[one][zero][flag][index] != -1){
        return dp[one][zero][flag][index] %MOD;
    }

    int highest = 9;
    if (flag){
        highest = s[index]-'0';
    }
    int ret = 0;
    bool ms;
    for (int i=0; i<=highest; i++){
        if (i < s[index]-'0'){
            ms = 0;
        }
        else{
            ms = flag;
        }
        if (i == 1){
            ret += solve(index+1, 1, zero, ms);
        }
        else if (i == 0){
            if (one){
                if (!zero){
                    ret += solve(index+1, one, 1, ms);
                }
            }
            else{
                ret += solve(index+1, 0,0,ms);
            }
        }
        else{
            ret += solve(index+1, one, zero, ms);
        }
        ret %= MOD;
    }
    ret %= MOD;
    dp[one][zero][flag][index] = ret;
    return ret;
}


int main() {
    cin >> s;
    len = s.length();
    memset(dp, -1, sizeof(dp));
    cout << solve(0,0,0,1) << "\n";
}