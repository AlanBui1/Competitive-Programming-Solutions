#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e3 + 5;

//dsu + bsearch
int parent[MAXSZ], n;

double x[MAXSZ], y[MAXSZ];

int findSet(int a){
    return a==parent[a] ? a : parent[a] = findSet(parent[a]);
}

void unionsets(int a, int b){
    a = findSet(a); b = findSet(b);
    parent[b] = a;
}

double sq(double _){
    return _*_;
}

double sqDist(double x1, double y1, double x2, double y2){
    return sq(x1 - x2) + sq(y1 - y2);
}

bool works(double r){
    int comps = n;

    for (int i=0; i<MAXSZ; i++){
        parent[i] = i;
    }

    for (int i=0; i<n; i++){
        for (int k=i+1; k<n; k++){
            if (sqDist(x[i], y[i], x[k], y[k]) <= 4*sq(r)){
                if (findSet(i) != findSet(k)){
                    unionsets(i, k);
                    comps --;
                }
            }
        }
    }

    return comps == 1 ? true : false;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> x[i] >> y[i];
    }

    double lo = 0, hi = 500000000, ans = 500000000;

    while (hi - lo >= 1e-7){
        double mid = (lo+hi)/2;

        if (works(mid)){
                //cout << mid << "\n";
            ans = min(mid, ans);
            hi = mid-0.0000001;
        }
        else{
            lo = mid+0.0000001;
        }
    }
    cout << fixed << setprecision(6) << ans << "\n";
}