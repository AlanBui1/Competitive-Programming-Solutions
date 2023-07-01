#include <bits/stdc++.h>
using namespace std;

long long a, b;
string s1, s2;
long long len;

int64_t dp[2][16][10][16][1000];
string s;

long long solve(int index, bool flag, int prev, int cnt, long long ans, bool added){

    if (index == len){
        ans += prev*cnt*cnt;
        return ans;
    }

    if (ans < 1000){
        if (dp[flag][index][prev][cnt][ans] != -1){
            return dp[flag][index][prev][cnt][ans];
        }
    }

    int highest = 9;
    if (flag){
        highest = s[index]-'0';
    }

    bool ns;
    long long ret = 0;

    for (int i=0; i<=highest; i++){
        if (i < s[index]-'0'){
            ns = 0;
        }
        else{
            ns = flag;
        }

        if (!added && i == 0){
            ret += solve(index+1, ns, prev, cnt, ans, 0);
        }
        else{
            if (i == prev){
                ret += solve(index+1, ns, prev, cnt+1, ans, 1);
            }
            else{
                ret += solve(index+1, ns, i, 1, ans+(prev*cnt*cnt), 1);
            }
            
        }
    }
    if (ans < 1000) dp[flag][index][prev][cnt][ans] = ret;
    return ret;

}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> a >> b;
    a--;
    s1 = to_string(a);
    s2 = to_string(b);

    len = s2.length();
    memset(dp, -1, sizeof(dp));
    s = s2;
    long long ans1 = solve(0, 1, 0,0, 0, 0);

    len = s1.length();
    s = s1;
    memset(dp, -1, sizeof(dp));
    ans1 -= solve(0,1,0,0,0,0);
    cout << ans1 << "\n";

    // cout << sizeof(dp);
}