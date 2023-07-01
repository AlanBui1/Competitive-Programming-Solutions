#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
int n, want, len;
string s;
const int d1 = 2, d2=1015, d3=(1<<11);

long long dp[d1][d2][d3];

long long solve(long long index, bool flag, long long mask, bool added){
    if (mask >= (1<<12)-1){
        cout << mask << "DEAD\n";
    }
    if (index == len){
        if ((mask & want) == want){
            return 1;
        }
        return 0;
    }

    if (dp[flag][index][mask] != -1){
        return dp[flag][index][mask];
    }

    int lim = 9;
    if (flag){
        lim =s[index]-'0';
    }

    long long ret = 0;
    bool ns;

    for (int i=0; i<=lim; i++){
        
        if (i < s[index]-'0'){
            ns = 0;
        }
        else{
            ns = flag;
        }

        if (!added && i == 0){
            ret += solve(index+1, ns, mask,  0);
            continue;
        }

        ret += solve(index+1, ns, mask|(1 << i) ,1)%MOD;
        ret %= MOD;
    }

    dp[flag][index][mask] = ret%MOD;
    return ret%MOD;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for (int i=0; i<n; i++){
        int a; cin >> a;
        want |= (1<<a);
    }

    cin >> s;
    len = s.length();

    

    for (int i=0; i<d1; i++){
        for (int k=0; k<d2; k++){
            for (int j=0; j<d3; j++){
                dp[i][k][j] =-1;
            }
        }
    }

    long long ans =  solve(0, 1, 0, 0)%MOD;
    if (n == 1 && want == 1){
        ans++;

    }
    
    cout << ans << "\n";

}