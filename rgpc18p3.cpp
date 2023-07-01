#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e6+5;

int arr[MAXSZ];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n,t; cin >> n >> t;

    for (int i=0; i<t; i++){
        int a, b, c; cin >> a >> b>> c;

        arr[a]+=c;
        arr[b+1]-=c;
    }

    for (int i=0; i<=n; i++){
        arr[i] += arr[i-1];
    }
    for (int i=0; i<=n; i++){
        arr[i] += arr[i-1];

    }


    int l; cin >> l;

    int p1=1, p2=1, ans=0;
    while (p1 <= n && p2 <= n){
        if (arr[p2]-arr[p1] <l){
            ans = max(ans, p2-p1+1);
            p2++;
            
        }
        else{
            p1++;
        }

    }
    
    cout << ans << "\n";
}