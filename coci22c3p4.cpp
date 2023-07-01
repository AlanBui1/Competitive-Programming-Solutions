#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 505;
const int MOD = 998244353;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

unordered_map<int, int> top[MAXSZ], lef[MAXSZ], cur[MAXSZ];

int32_t a[MAXSZ][MAXSZ];

int32_t main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N, K; cin >> N >> K;

    for (int i=0; i<N; i++){
        for (int k=0; k<N; k++){
            cin >> a[i][k];
            a[i][k] %= K;
        }
    }

    if (a[0][0] != -1){
        top[0][K / gcd(a[0][0], K)] = 1;
        lef[0][K / gcd(a[0][0], K)] = 1;
    }

    //left side
    for (int i=1; i<N; i++){
        if (a[i][0] == -1) break;
        for (pair <long long, long long> PII : lef[i-1]){
            lef[i][PII.first / gcd(PII.first, a[i][0])] += PII.second;
        }
    }

    //top side
    for (int j=1; j<N; j++){
        if (a[0][j] == -1) break;
        for (pair <long long, long long> PII : top[j-1]){
            top[j][PII.first / gcd(PII.first, a[0][j])] += PII.second;
        }
    }

    for (int i=1; i<N; i++){
        cur[0] = lef[i];
        for (int j=1; j<N; j++){
            cur[j].clear();
            if (a[i][j] == -1) continue;
            for (pair <long long, long long> PII : top[j]){
                cur[j][PII.first / gcd(PII.first, a[i][j])] += PII.second;
                cur[j][PII.first / gcd(PII.first, a[i][j])] %= MOD;
            }
            for (pair <long long, long long> PII : cur[j-1]){
                cur[j][PII.first / gcd(PII.first, a[i][j])] += PII.second;
                cur[j][PII.first / gcd(PII.first, a[i][j])] %= MOD;
            }
        }
        for (int _ = 0; _ < MAXSZ; _++){
            top[_] = cur[_];
        }
    }

    cout << cur[N-1][1] << "\n";

}