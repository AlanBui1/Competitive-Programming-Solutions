#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;
ll m;
ll factor;

ll GCD(ll a, ll b) {return (b == 0 ? a : GCD(b,a%b));}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> m;
    factor=m;
    n--;
    while (n--){
        cin >> m;
        factor = GCD(factor, m);
    }
    if (factor == 1){
        cout << "DNE\n";
        return 0;
    }
    ll highest = -1, orig = factor;
    
    while (factor %2 == 0){
        factor /= 2;
        highest = 2;
    }

    while (factor %3 == 0){
        factor /= 3;
        highest = 3;
    }
    
    for (ll i=3; i*i<=orig; i++){
        while (factor%i == 0){
            factor /= i;
            highest = max(highest, i);
        }
    }
    if (highest == -1){
        highest = factor;
    }
    
    cout << highest << "\n";
}