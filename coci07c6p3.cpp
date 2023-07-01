#include <bits/stdc++.h>
using namespace std;
#define int long long

const int nax = 105;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int arr[nax];

vector <int> s;

int32_t main(){
    int n; cin >> n;

    for (int i=1; i<=n; i++) cin >> arr[i];

    int g = 0;

    for (int i=1;i<n; i++){
        g = gcd(abs(arr[i]-arr[i+1]), g);
    }

    for (int i=2; i*i <= g; i++){
        if (g%i == 0){
            s.push_back(i);
            if (i != g/i){
                s.push_back(g/i);
            }
        }
    }

    for (int i=0; i<s.size(); i++) cout << s[i] << " ";
    cout << g << "\n";

}