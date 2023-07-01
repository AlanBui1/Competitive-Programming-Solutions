#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
const int inf = 1e9;

int dp[MAXSZ];
int coins[MAXSZ];
vector <pair <int, pair <int, int>>> queries;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, v; cin >> n >> v; 

    for (int i=0; i<n; i++) cin >> coins[i];

    int amt, coin;
    for (int i=0; i<v; i++){
        cin >> amt >> coin;
        queries.push_back({coin, {amt,i}});
    }

    sort(queries.begin(), queries.end());

    for (int i=0; i<MAXSZ; i++) dp[i] = inf;
    dp[0] =0;
    int curCoin = 0;
    int ans[v];

    for (int i=0; i<v; i++){
        if (queries[i].first <= curCoin){
            if (dp[queries[i].second.first] != inf){
                ans[queries[i].second.second]= dp[queries[i].second.first];
            }
            else ans[queries[i].second.second] = -1;
        }
        else{
            for (; curCoin < queries[i].first; curCoin++){
                int newCoin = coins[curCoin];
                dp[newCoin] = 1;
                for (int k=newCoin+1; k<MAXSZ; k++){
                    if (dp[k-newCoin] != inf){
                        dp[k] = min(dp[k], dp[k-newCoin]+1);
                    }
                }
            }
            if (dp[queries[i].second.first] != inf){
                ans[queries[i].second.second]= dp[queries[i].second.first];
            }
            else ans[queries[i].second.second] = -1;
        }
    }

    for (int i=0; i<v; i++) cout << ans[i] << "\n";

}