#include <bits/stdc++.h>
using namespace std;
const int nax = 105;

int parent[nax], siz[nax];

int find(int a){
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}

int lcm (int a, int b) {
    return a / gcd(a, b) * b;
}

int ans(vector <int> v){
    int a = 1;
    for (int i : v){
        a = lcm(a, i);
    }
    return a;
}

void unionsets(int a, int b){
    if (siz[a] > siz[b]) swap(a, b);
    parent[b] = a;
    siz[a]+=siz[b];
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    while (n){
        vector <int> sizes;
        sizes.clear();

        for (int i=0; i<nax; i++){
            siz[i] = 1;
            parent[i] = i;
        }

        for (int i=0; i<n; i++){
            int a, b; cin >> a>>b;
            a = find(a); b = find(b);

            if (a != b){
                unionsets(a, b);
            }
        }
        for (int i=1; i<=n; i++){
            if (siz[find(i)] != -1){
                sizes.push_back(siz[find(i)]);
                siz[find(i)] = -1;
            }
        }

        cout << ans(sizes) << "\n";

        cin >> n;
    }
}