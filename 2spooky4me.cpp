#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5;
#define f first
#define s second
#define ll long long
#define pb push_back
ll n, S, l, arr[MAXSZ];
unordered_map <ll, ll> convert;
vector <pair <pair <ll, ll>, ll>> houses;
vector <ll> nums;
ll rconvert[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> l >> S;

    ll a, b, c;
    for (int i=0; i<n; i++){
        cin >> a >> b>> c;
        nums.pb(a);
        nums.pb(b);
        nums.pb(b+1);
        houses.pb({{a, b}, c});
    }

    sort(nums.begin(), nums.end());
    
    ll cnt=1;
    for (int i=0; i<nums.size(); i++){
        if (nums[i] != nums[i-1]){
            convert[nums[i]] = cnt;
            rconvert[cnt] = nums[i];
            cnt++;
            
            // cout << nums[i] << " " << convert[nums[i]] << "\n";
        }
    }
    rconvert[cnt+1] = l;

    for (pair < pair <ll,ll>, ll > house : houses){
        ll start=house.f.f, stop=house.f.s, val=house.s;
  
        arr[convert[start]] += val;
        arr[convert[stop+1]] -= val;
    }

    for (int i=1; i<MAXSZ; i++){
        // cout << arr[i] << " ";
        arr[i] += arr[i-1];
        // cout << arr[i] << " ";
        
    }
    // cout << "\n";

    for (int i=0; i<MAXSZ; i++){
        if (arr[i] >= S){
            // cout << i << " " << arr[i] << " " << rconvert[i] << "\n";
            l -= rconvert[i+1]-rconvert[i];
        }
    }

    // for (int i=1; i<7; i++){
    //     cout << i << " " << rconvert[i] << " " << convert[rconvert[i]] << "\n"; 
    // }
    // cout << "\n";

    cout << l << "\n";
    // cout << rconvert[3] << "\n";
}