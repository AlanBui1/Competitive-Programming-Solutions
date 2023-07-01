#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define f first
#define s second

int w, h, n;
const int MAXSZ = 255;
int prefix[MAXSZ][MAXSZ];
vector <pair<int,int>> factors;

int main() {
    scan(w); scan(h); scan(n);

    for (int i=1; i<=h; i++){
        for (int k=1; k<=w; k++){
            scan(prefix[i][k]);
            prefix[i][k] += prefix[i-1][k] + prefix[i][k-1] - prefix[i-1][k-1];
            // cout << prefix[i][k] << " ";
        }
        // cout << "\n";
    }
    
    for (int i=1; i<= sqrt(n); i++){
        // if (n%i == 0){
        factors.push_back({i, n/i});
        factors.push_back({n/i, i});
            // cout << i << " " << n/i << "\n";
        // }
    }
    int ans=0;
    for (int i=h; i>=1; i--){
        for (int k=w; k>=1; k--){
            for (pair<int, int> fac : factors){
                int f1 = fac.f, f2 =fac.s;
                f1 = max(0, i-f1); f2 = max(0, k-f2);
                ans = max(ans, prefix[i][k]-prefix[f1][k]-prefix[i][f2]+prefix[f1][f2]);
            }
        }
    }
    cout << ans << "\n";
}