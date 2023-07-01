#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define ll long long
ll c, t;
vector <ll> ppl;
ll psa[MAXSZ], x,  highest=0, lowest = -1;

bool works(ll r){
    auto x =lower_bound(ppl.begin(), ppl.end(), r);
    ll ind;
    if (x == ppl.end()){
        ind = c;
    }
    else ind = x - ppl.begin();
    ll cost = r*ind;

    return t >= cost-psa[ind];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> c >> t;

    for (int i=0; i<c; i++){
         cin >> x;
        ppl.push_back(x);
        highest = max(highest, x);
        lowest = min(lowest, x);
    }

    sort(ppl.begin(), ppl.end());
    for (int i=0; i<c; i++){
        psa[i+1] = psa[i]+ppl[i];
       
    }


    ll ans= lowest;

    ll L = lowest, R = highest+t;

    while (L <= R){
        ll mid = (L+R)/2;

        if (works(mid)){
            ans = max(ans, mid);
            L=mid+1;
        }

        else{
            R = mid-1;
        }

    }

    cout << ans << "\n";


}