#include <bits/stdc++.h>
using namespace std;

vector <int> nums;
unordered_map <int, int> freq;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n,q, x, v; cin >> n;

    for (int i =0; i<n; i++){
        cin >> x;
        nums.push_back(x);
        freq[x]++;
    }

    sort(nums.begin(), nums.end());

    cin >> q;

    while (q--){
        cin >> v;
        int ans = *lower_bound(nums.begin(), nums.end(), v);

        cout << ans << " " << freq[ans] << "\n";
    }
}