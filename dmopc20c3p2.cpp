#include <bits/stdc++.h>
using namespace std;
#define int long long
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAXSZ = 2e5+5;
const int inf = 2e9;

int parallels(int x){
    return (x-1)*x/2;
}

int hashes(int a, int b){
    return a*inf + b;
}

int arr[25][MAXSZ];
unordered_set <int> s[25];

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int m, n, k; scan(m); scan(n); scan(k);
    //cin >> m >> n >> k;

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            scan(arr[j][i]);
            //cin >> arr[j][i];
        }
    }

    int ans = 0;

    for (int i=0; i<n-1; i++){
        for (int j=0; j<m; j++){
            s[i].insert(hashes(arr[i][j], arr[i+1][j]));
            s[i].insert(hashes(arr[i][j] + k, arr[i+1][j] + k));
        }
        int cnt = (2*m) - s[i].size();
        //ans += parallels(cnt);
        ans += cnt;
        //cout << cnt << " ";
    }
    cout << ans << "\n";
}