#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define ll long long

ll arr[MAXSZ];
vector <ll> students;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for(int i=0; i<n; i++){
        int a; cin >> a;
        students.push_back(a);
    }
    sort(students.begin(), students.end());

    for (int i=0; i<q; i++){
        int l, r; cin >> l >> r;
        arr[l]++; arr[r+1]--;
    }
    for (int i=1; i<MAXSZ; i++){
        arr[i] += arr[i-1]; 
    }

    sort(arr, arr+n+1);

    ll s = 0;
    
    for (int i=0; i<n; i++){

        s += arr[i+1]*students[n-i-1];
    }
    cout << s << "\n";
}