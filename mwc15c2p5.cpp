#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXSZ = 1e5+5;

int arr[5][MAXSZ], ans[5];

signed main(){
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, K, j; cin >> n >> K >> j;
    
    for (int i=0 ;i<j; i++){
        int xi, xf, I, T; cin >> xi >> xf >> I >> T;
        arr[T][xi]+=I;
        arr[T][xf+1]-=I;
    }
    
    
    for (int i=1; i<=3; i++){
        for (int k=1; k<=n; k++){
            arr[i][k] += arr[i][k-1];
            if (arr[i][k] < K) ans[i]++;
        }
    }
    for (int i=1; i<=3; i++) cout << ans[i] << "\n";
    
    
    
}