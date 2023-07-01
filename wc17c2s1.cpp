#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;

unordered_map <int, int> conv, rev;
vector <int> legolas, gimli;

auto lsum(int lim, int len){
    auto s = lower_bound(legolas.begin(), legolas.end(), lim);
    return len - (s - legolas.begin());
}
int gsum(int lim, int len){
    auto s = lower_bound(gimli.begin(), gimli.end(), lim);
    return len - (s - gimli.begin());
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int l, g; cin >> l >> g;

    int x;
    for (int i=0; i<l; i++){
        cin >> x;
        legolas.push_back(x);
    }
    for (int i=0; i<g; i++){
        cin >> x;
        gimli.push_back(x);
    }


    int ans = -1;

    sort(legolas.begin(), legolas.end());
    sort(gimli.begin(), gimli.end());

    int L = 0, R = g;

    for (int i=L; i<R; i++){
        int M = gimli[i];
        if (lsum(M, l) < gsum(M, g)){
            ans = M; 
            break;
        }
    }

    cout << ans << "\n";

}