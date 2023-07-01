#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXSZ=1e6+5;
vector <ll> trees;

ll psa[MAXSZ];
ll n, m, x, highest =0;

bool works(int r){
    auto it = upper_bound(trees.begin(), trees.end(), r);

    ll get =(psa[n]-psa[it-trees.begin()])-(r*(n-(it-trees.begin())));

    return get >= m;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

     cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> x;
        trees.push_back(x);
        highest = max(highest, x);
    }

    sort(trees.begin(), trees.end());

    for (int i=1; i<=n; i++){
        psa[i] = psa[i-1]+trees[i-1];      
    }

    ll L = 0, R = highest, ans =-1;

    while (L <= R){
        ll mid = (L+R)/2;

        if (works(mid)){
            L = mid+1;
            ans= max(ans, mid);
        }
        else{
            R = mid-1;
        }
    }

    cout << ans << "\n";
}