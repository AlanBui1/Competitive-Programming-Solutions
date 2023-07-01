#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 1005;

#define pii pair <int, int>
set <pii> employees;

string names[MAXSZ];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i=0; i<n; i++){
        int s; string name; cin  >> name >> s;
        names[i] = name;

        employees.insert({s, i});
    }

    int x; cin >> x;
    while (x--){
        int v, d; cin >> v >> d;

        auto it = *employees.lower_bound({v, 0});
        if (v <= it.first && it.first <= v+d){
            cout << names[it.second] << "\n";
        }
        else{
            cout << "No suitable teacher!\n";
        }

    }
}