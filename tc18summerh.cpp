#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 5e4+4;
const int inf = 2e9;
int words[MAXSZ], n;

int cnt(int mask){
    int ret = 0;
    for (int i=0; i<20; i++){
        if ((1 << i) & mask){
            ret ++;
        }
    }
    return ret;
}

bool works(int mask){
    int c = 0;

    for (int i=0; i<n; i++){
        if ((words[i] & mask) == mask){
            c++;
            //cout << i << "\n";
        }
        if (c >= 2) return 0;
    }
    return c == 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0; i<n; i++){
        string s; cin >> s;
        for(int k=0; k<s.size(); k++){
            words[i] |= (1 << (s[k]-'a'));
        }
    }

    int ans = inf;

    for (int mask=0; mask<(1 << 20); mask++){
        if (cnt(mask) >= ans) continue;
        if (works(mask)){
            ans = min(ans, cnt(mask));
        }
    }

    if (ans == inf){
        cout << "-1\n";
    }
    else cout << ans << "\n";
    //cout << works((1 << 0) | (1 << 19) | (1 << 16));
    //cout << cnt((1 << 0) | (1 << 19) | (1 << 16));
}