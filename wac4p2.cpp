#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int, int>
#define f first
#define s second
const int MAXSZ=1e5;
const int inf = 1e18;

int n;
vector <pii> ops;
int dp[MAXSZ];

int32_t main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >>n;

    int a, p;
    int tot=0;
    for (int i=0; i<n; i++){
        cin >> a >> p;
        tot+=p;
        ops.push_back({a/2+1, p});
    }

    int need = tot/2 +1;

    for (int i=0; i<MAXSZ; i++){
        dp[i] = inf;
    }

    dp[0] = 0;

    for (pii O : ops){
        int cost = O.f, profit = O.s;
        for (int i=MAXSZ-1; i>=0; i--){
            if (i-profit >= 0){
                dp[i] = min(dp[i-profit]+cost, dp[i]);
            }
            else{
                break;
            }
        }
    }
    int ans = inf;
    for (int i=MAXSZ-1; i>=need; i--){
        ans = min(ans, dp[i]);
    }
    cout << ans << "\n";


}