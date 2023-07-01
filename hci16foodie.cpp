#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

bool dp[MAXSZ];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int c, n; cin >> c >> n;
    dp[0] = 1;
    
    for (int i=0; i<n; i++){
        int cal; cin >> cal;
        
        for (int i=c-1; i>=0; i--){
            if (i - cal < 0) break;
            if (dp[i - cal]){
                dp[i] = 1;
            }
        }
    }
    
    for (int i=c-1; i>=0; i--){
        if (dp[i]){
            cout << i << "\n";
            return 0;
        }
    }
}