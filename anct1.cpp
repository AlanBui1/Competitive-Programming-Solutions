#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    d = abs(d);

    int j;
    int ans = -1;
    for (int i=0; i<n; i++){
        cin >> j;
        if (d%j == 0){
            if (j>ans){
                ans = j;
            }
        }
    }
    if (d == 0){
        cout << 0 << "\n";
    }
    else if (ans != -1){
        cout << d/ans << "\n";
    }
    else{
        cout << "This is not the best time for a trip."<<"\n";
    }
}