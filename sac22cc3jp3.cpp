#include <bits/stdc++.h>

using namespace std;

unordered_map <char, double> conv;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    double prob = 1;
    conv['A'] = 1.0;
    conv['B'] = 0.8;
    conv['C'] = 0.6;
    conv['D'] = 0.4;
    conv['E'] = 0.2;
    
    int n; cin >> n;
    while (n--){
        char c; cin >> c;
        prob *= conv[c];
    }
    cout << fixed << setprecision(6) << prob << "\n";
    
    return 0;
}