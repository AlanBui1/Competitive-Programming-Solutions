#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e3+5;
const double eps = 0.000001;

double arr[MAXSZ][MAXSZ];

int n, m;

double f(double x){
    double ret = 0, one =1;
    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            ret += min(one, arr[i][k]*x);
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    double x = 0;
    for (int i=0; i<n; i++){
        for (int k=0; k<m; k++){
            cin >> arr[i][k];
            x += arr[i][k];
        }
    }

    if (abs(x - 0.48*n*m) <= eps){
        cout << "correctly exposed\n";
        return 0;
    }

    double lo = 0, hi = 1000;

    while (hi - lo > eps){
        double mid = (lo+hi)/2;

        double val = f(mid);

        if (val == 0.48*n*m){
            if (mid == 1){
                cout << "correctly exposed\n";
                return 0;
            }

            if (x < 0.48*n*m){
                cout << "underexposed\n";
            }
            else{
                cout << "overexposed\n";
            }
            cout << mid << "\n";
            return 0;
        }

        if (val < 0.48*n*m){
            lo = mid+eps;
        }
        else{
            hi = mid-eps;
        }
    }
    if (abs(lo - 1) <= eps){
        cout << "correctly exposed\n";
        return 0;
    }
    if (x < 0.48*n*m){
        cout << "underexposed\n";
    }
    else{
        cout << "overexposed\n";
    }

    cout << lo << "\n";

}