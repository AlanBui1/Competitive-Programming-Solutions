#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 2e5+5;

int t[MAXSZ], n, ans;

int val(int x){
    int ret = 0;
    for (int i=1; i<=n; i++){
        ret += t[i]/x*x;
    }
    return ret;
}

int main(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> t[i];
    }
    for (int i=2; i<=24; i++){
        ans = max(ans, val(i));
    }

    cout << ans << "\n";

}