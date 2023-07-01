#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int INF = 1e9;
const int MAXSZ = 1e5+5;

int n, m;
vector <ll> a, b;

int bsearch(int v, int lo, int hi){
    int ret = INF;

    while (lo <= hi){
        int mid = (lo+hi)/2;

        if (b[mid] >= v){
            ret = mid;
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return ret;

}

bool works(int x){
    int L = 0, R = m-1;

    for (int i=0; i<n; i++){
        int ind = bsearch(a[i] - x, L, R);

        if (ind == INF) return 0;
        if (abs(a[i] - b[ind]) > x) return 0;

        L = ind+1;
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        ll x; cin >> x;
        a.push_back(x);
    }

    for (int i=0; i<m; i++){
        ll x; cin >> x;
        b.push_back(x);
    }

    if (n > m){
        swap(a, b);
        swap(n, m);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 0;
    if (n == m){
        for (int i=0; i<n; i++){
            ans = max(ans, abs(a[i] - b[i]));
        }
        cout << ans << "\n";
    }

    else{
        int lo = 0, hi = b[m-1];
        ans = hi;
        while (lo <= hi){
            int mid = (lo+hi)/2;

            if (works(mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        cout << ans << "\n";
    }
}