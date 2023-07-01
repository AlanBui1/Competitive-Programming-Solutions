#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;

int ones[MAXSZ], zeros[MAXSZ], ans = MAXSZ;

bool works(int L, int R, int want, int t){
    if (t == 0){
        return (zeros[R]-zeros[L-1] >= want);
    }
    return (ones[R] - ones[L-1] >= want);
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int cur = 1;
    for (char c : s){
        if (c == '0'){
            zeros[cur]++;
        }
        else{
            ones[cur]++;
        }
        cur ++;
    }
    for (int i=1; i<=s.length(); i++){
        ones[i] += ones[i-1];
        zeros[i] += zeros[i-1];
        // cout << ones[i] << " " << zeros[i] << "\n";
    }
    int q; cin >> q;
    while (q--){
        int x, y, z;
        cin >> x >> y >> z;
        int L = x, R = s.length();
        ans = MAXSZ;
        while (L <= R){
            int mid = (L+R)/2;
            
            // cout << x << " " << mid << " " << y << " " << z << " " << works(x, mid, y, z) << " " << zeros[mid]-zeros[x-1] << "\n";

            if (works(x, mid, y, z)){
                R = mid-1;
                ans = mid;
            }
            else{
                L = mid+1;
            }
        }

        if (ans == MAXSZ){
            cout << "-1\n";
        }
        else{
            cout << ans << "\n";
        }
    }
}