#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 1e5+5;

vector <int> freq[MAXSZ];

bool find(int l, int r, int i){
    auto ind = lower_bound(freq[i].begin(), freq[i].end(), l);
    if (ind == freq[i].end()) return 0;
    return l <= *ind && *ind <= r;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q, x; cin >> n >> q;

    for (int i=1; i<=n; i++){
        cin >> x;
        freq[x].push_back(i);
    }
    int l, r;
    bool flag;
    while (q--){
        cin >> l >> r >> x;
        flag = 0;
        for (int i=1; i*i < x; i++){
            if (x%i == 0){
                if (find(l, r, i) && find(l, r, x/i)){
                    flag = 1;
                    break;
                }
            }
        }

        if (flag){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}