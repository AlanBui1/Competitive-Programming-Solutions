#include <bits/stdc++.h>
using namespace std;

double f(double x){
    return (12*(x*x))-(5*x)+1;
}

int main(){
    int lim; cin >> lim;

    double L = 0, R = lim;
    double ans = 0;

    while (R - L >= 1e-7){
        double mid= (L+R)/2;

        if (f(mid) <= lim){
            ans = max(ans, mid);
            L = mid+1e-7;
        }
        else{
            R = mid-1e-7;
        }

    }
    cout << fixed << setprecision(6) << ans << "\n";
}