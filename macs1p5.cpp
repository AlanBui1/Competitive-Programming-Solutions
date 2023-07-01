#include<bits/stdc++.h>
using namespace std;

const int MAXSZ = 50005;
const int INF = 2e9+7;

int N, K, dp[MAXSZ][105], a[MAXSZ];
int BIT1[MAXSZ][105], BIT2[MAXSZ][105];

void upd1(int i, int x, int v){
    for (; i<MAXSZ; i+= i&-i){
        BIT1[i][x] = min(BIT1[i][x], v);
    }
}
int query1(int i, int x){
    int ret=INF;
    for (; i>0; i-=i&-i){
        ret = min(ret, BIT1[i][x]);
    }
    return ret;
}

void upd2(int i, int x, int v){
    for (; i>0; i-=i&-i){
        BIT2[i][x] = min(BIT2[i][x], v);
    }
}
int query2(int i, int x){
    int ret=INF;
    for (; i<MAXSZ; i+=i&-i){
        ret = min(ret, BIT2[i][x]);
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for (int i=1; i<=N; i++){
        cin >> a[i];
    }

    for (int i=1; i<MAXSZ; i++){
        for (int j=1; j<105; j++){
            dp[i][j] = INF;
            BIT1[i][j]= INF;
            BIT2[i][j] = INF;
        }
    }

    //let dp[i][j] = min value of subsequence length j ending at index i
    //dp[i][j] = min(dp[k][j-1] - a[k]) + a[i] if a[i] > a[k])
    //dp[i][j] = min(dp[k][j-1] + a[k]) - a[i] if a[k] > a[i])

    for (int i=1; i<=N; i++){
        for (int j=2; j<=min(K, i); j++){
            dp[i][j] = min(a[i] + query1(a[i], j-1), query2(a[i], j-1) - a[i]);


        }
        dp[i][1] = 0;
        for (int j=1; j<=min(K, i); j++){
            upd1(a[i], j, dp[i][j] - a[i]);
            upd2(a[i], j, dp[i][j] + a[i]);
        }
    }



    int ans = INF;
    for (int i=K; i<=N; i++){
        ans = min(ans, dp[i][K]);
    }
    cout << ans << "\n";

}