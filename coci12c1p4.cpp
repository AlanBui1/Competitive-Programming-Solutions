#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXSZ = 1e6+5;
const int inf = 1e9+7;

int arr[MAXSZ];

bool work (int x, int n, int m){
    int ppl = 0;
    
    for (int i=0; i<m; i++){
        ppl += (arr[i]/x) + (arr[i]%x > 0);
    }
    
    return ppl <= n;
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, m; cin >> n >> m;
    
    for (int i=0; i<m; i++){
        cin >> arr[i];
    }
    
    int lo = 1, hi = inf, ans = inf;
    
    while (lo <= hi){
        int mid = (lo+hi)/2;
        
        if (work(mid, n, m)){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    
    cout << ans << "\n";
    
    
}