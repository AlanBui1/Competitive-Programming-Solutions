#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXSZ = 1e6;

unordered_map <ll, ll> conv;
ll arr[MAXSZ], rconv[MAXSZ], ans[MAXSZ];

const ll inf = 2e9+5;

struct num{
    ll val, add;
};

vector <num> nums;
bool compare(num x, num y){
    return x.val < y.val;
}

int main(){
    cin.sync_with_stdio(0);cin.tie(0);

    int n; cin >> n;

    ll l, r, y; cin >> l >> r >> y;

    for (int i=0; i<n; i++){
        ll x, v, h; cin >> x >> v >> h;

        /*
        SOLVE FOR xR
        y = (v/h)x - (v/h)x_i
        hy = vx - vx_i
        vx - hy - vx_i = 0
        */

        ll lo = l, hi = r, xL = inf, xR = -inf;

        while (lo <= hi){
            ll mid = (lo+hi)/2;

            ll val = (v*mid) - (h*y) - (v*x);

            if (val < 0){
                xR = max(xR, mid);
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        lo = l; hi = r;

        while (lo <= hi){
            ll mid = (lo+hi)/2;

            ll val = (v*mid) + (h*y) - (v*x);

            if (val > 0){
                xL = min(xL, mid);
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }

        if (l <= xL && xL <= r){
            num L; L.add = 1; L.val = xL;
            nums.push_back(L);
        }

        if (l <= xR && xR <= r){
            num R; R.add = -1; R.val = xR+1;
            nums.push_back(R);

        }

    }

    num start; start.add =0;start.val = l;
    num finish; finish.add = 0; finish.val = r;

    nums.push_back(start); nums.push_back(finish);
    start.val --;
    nums.push_back(start);
    finish.val++;
    nums.push_back(finish);

    sort(nums.begin(), nums.end(), compare);

    ll cnt = -1;
    ll prev = -inf-1;

    for (num N : nums){
        if (N.val != prev){
            cnt++;
            conv[N.val] = cnt;
            rconv[cnt] = N.val;
        }
        arr[conv[N.val]] += N.add;
        prev= N.val;
    }

    for (int i=1; i<MAXSZ; i++){
        arr[i] += arr[i-1];
    }
    for (int i=1; i<MAXSZ; i++){
        arr[i] += arr[i-1];
    }

    for (int i=2; i<=cnt; i++){

        ans[ arr[i-1] - arr[i-2]] += rconv[i] - rconv[i-1];
    }

    for (int i=1; i<=n+1; i++){
        ans[i] += ans[i-1];
    }
    for (int i=0; i<=n; i++){
        cout <<ans[i]<< "\n";
    }


}