#include <bits/stdc++.h>
using namespace std;

int main() {
    int q = 5;
    while (q--){
        int n; cin >> n;
        double x=0;
        for (int i=1; i<=n; i++){
            x += log10(i);
        }
        cout << "The length of " << n << "! is " << floor(x)+1 << "\n";
    }
}