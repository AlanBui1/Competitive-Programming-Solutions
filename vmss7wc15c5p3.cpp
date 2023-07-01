#include <bits/stdc++.h>
using namespace std;

const int nax = 2005;
const int MOD = 1e9+7;
int BIT[nax][nax], ans;

void upd(int bit, int idx, int v){
    for (; idx < nax; idx+=idx & (-idx)){
        BIT[bit][idx] += v;
    }
}

int sum(int bit, int idx){
    int ret = 0;
    for (; idx > 0; idx -= (idx & (-idx))){
        ret += BIT[bit][idx];
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int Q; cin >> Q;

    while (Q--){
        int op, a, b, c; cin >> op;
        cin >> a >> b >> c;

        if (op == 1){
            upd(a + b, a, c);
        }
        else{
            ans += sum(a+b, a) - sum(a+b, a-c-1) ;
            ans %= MOD;
        }
    }
    cout << ans << "\n";

}