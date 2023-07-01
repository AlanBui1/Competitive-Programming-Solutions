#include <bits/stdc++.h>
using namespace std;
#define intt __int32_t
const int MAXSZ=5003;

intt up[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    intt n; cin >> n;

    string s; cin >> s;

    if (n == 1){
        cout << 0 << "\n";
        return 0;
    }
    intt ans=0;

    intt nxt[MAXSZ];

    for (int i=1; i<=n+1; i++){
        for (int i=0; i<=n+1; i++) nxt[i] =0;

        for (int k=1; k<= n+1;k++){
            nxt[k] = max(up[k], nxt[k-1]);

            if (s[i-1] == s[n-k+1]){
                nxt[k] = up[k-1]+1;
            }
            ans = max(ans, nxt[k]);
        }
        for (int i=0; i<=n; i++) up[i] = nxt[i];
    }  
    
    cout << n-ans << "\n";
}