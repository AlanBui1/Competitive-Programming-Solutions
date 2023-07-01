#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 3e5+5;
const int MAXN = 2e6+5;

int view[MAXSZ], a[MAXSZ], b[MAXSZ], psa[MAXN];
vector <int> nums;
unordered_map <int, int> conv;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for (int i=0; i<n; i++){
        cin >> view[i];
        nums.push_back(view[i]);
    }

    int q; cin >> q;

    for (int i=1; i<=q; i++){
        cin >> a[i] >> b[i];
        nums.push_back(a[i]);
        nums.push_back(b[i]);
        nums.push_back(a[i]-1);
    }

    sort(nums.begin(), nums.end());

    int cnt = 1;
    conv[nums[0]] = 1;

    int x = nums.size();
    for (int i=1; i<x; i++){
        if (nums[i] != nums[i-1]){
            cnt++;
            conv[nums[i]] = cnt;
        }
    }

    for (int i=0; i<n; i++){
        psa[conv[view[i]]]++;
    }

    for (int i=1; i<MAXN; i++){
        psa[i] += psa[i-1];
    }

    for (int i=1; i<=q; i++){
        cout << psa[conv[b[i]]] - psa[conv[a[i]-1]] << "\n";
    }

    
}