#include <bits/stdc++.h>
using namespace std;
vector <int> ppl;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    int x;
    for (int i=0; i<n; i++){
        cin >> x;
        ppl.push_back(x);
    }
    sort(ppl.begin(), ppl.end());
    while (m--){
        cin >> x;
        cout << n-(lower_bound(ppl.begin(), ppl.end(), x) -ppl.begin())<< "\n";
    }
}