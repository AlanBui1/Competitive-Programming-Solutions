#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

const int nax = (1 << 23)+5;

const ll inf = 4e18;

ll arr[nax], dp[nax];

vector <int> path;

deque <ll> dq;
queue <ll> Q;

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    int n, k; cin >> n >> k;

    for (int i=1; i<=n; i++) cin >> arr[i];

    dp[0]= 0;
    Q.push(dp[0]);
    dq.push_back(dp[0]);

    for (int i=1; i<=n; i++){
        ll ret = dq.front();
        dp[i] = arr[i]+ret;

        Q.push(dp[i]);
        while (!dq.empty() &&  (dq.back() > dp[i])){
            dq.pop_back();
        }
        dq.push_back(dp[i]);

        if (Q.size() > k){
            if (dq.front() == Q.front()){
                dq.pop_front();
            }
            Q.pop();
        }
    }

    ll ans = inf, nxtVal = inf;
    int cur, nxt;

    for (int i=n; i>n-k; i--){
        if (ans > dp[i]){
            ans = dp[i];
            cur = i;
        }
    }
    cout << ans << "\n";

    while (cur != 0){
        path.push_back(cur);
        nxtVal = inf;
        for (int i=cur; i>=max(0, cur-k); i--){
            if (nxtVal > dp[i]){
                nxtVal = dp[i];
                nxt = i;
            }
        }
        cur = nxt;
    }
    reverse(path.begin(), path.end());
    for (int i=0; i<path.size()-1; i++){
        cout << path[i] << " ";
    }
    cout << path[path.size()-1] << "\n";
}