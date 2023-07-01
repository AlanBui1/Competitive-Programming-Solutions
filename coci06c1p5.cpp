#include <bits/stdc++.h>

using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
const int MAXK = 1 << 20;
int powers[21];

int n;
double dp[1<<20];
int ar[21][21];
double arr[21][21];
bool used[1<<20];

double solve(int curN, int mask){
    if (curN >= n) return 1;
    if (used[mask]) return dp[mask];

    used[mask] = true;

    double& ret = dp[mask];
    for (int i=0; i<n; i++){
        if (mask & powers[i]) ret = max(ret, arr[curN][i]* solve(curN+1, mask^powers[i]));
    }

    return dp[mask];
}

int main(){

    powers[0] = 1; for (int i=1; i<21; i++) powers[i] = powers[i-1]*2;
    scan(n);
    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            scan(ar[i][k]);
            arr[i][k] = double(ar[i][k])/100;
        }
    }
    dp[0] = 1;

    cout << fixed << setprecision(6) << solve(0, powers[n]-1)*100 << "\n";

}