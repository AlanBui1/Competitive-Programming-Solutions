#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    double m, n, k;
    cin >> m >> k >> n;
    
    for (int x = 0; x <= m; x++){
        if ((((double)(x) + k))/n >= 0.595){
            cout << x << "\n";
            return 0;
        }
    }
    cout << "have mercy snew\n";
    
}