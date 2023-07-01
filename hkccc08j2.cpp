#include <bits/stdc++.h>
using namespace std;

string s;

int S(int x){
    int ret = 0;

    while (x > 0){
        ret += x%10;
        x /= 10;
    }
    return ret;
}
void solve(){
    cin >> s;
    int n = 0;
    for (char c : s){
        n += c-'0';
    }

    while (n >= 10){
        n = S(n);
    }

    cout << n << "\n";
}

int main(){
    int t; cin >> t;

    while (t--){
        solve();
    }


}