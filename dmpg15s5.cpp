#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e4+5;

bool arr[MAXSZ][MAXSZ];

int main() {
    
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int a, b, c, d;
    while (m--){
        cin >> a >> b >> c >> d;
        
        c = a+c;
        d = b+d;

        a++; b++;
        arr[a][b] = (arr[a][b]+1) %2;
        arr[c+1][d+1] = (arr[c+1][d+1]+1) %2;
        arr[a][d+1]= (arr[a][d+1]+1) %2;
        arr[c+1][b] = (arr[c+1][b]+1) %2;
    }
    
    int ans=0;
    for (int i=1; i<=n; i++){
        for (int k=1; k<=n; k++){
            arr[i][k] = ((arr[i][k]+ arr[i-1][k])%2 + (arr[i][k-1] - arr[i-1][k-1])%2)%2;
            if (arr[i][k]){
                ans++;
            }
            // cout << arr[i][k] << " ";
        }
        // cout << "\n";
    }
    cout << ans << "\n";
    
}