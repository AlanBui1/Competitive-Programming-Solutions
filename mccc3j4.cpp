#include <bits/stdc++.h>
using namespace std;
const int nax = 2e3+5;

queue <pair <int, int>> s[nax];
int previ[nax];

int main() {
    cin.sync_with_stdio(); cin.tie(0);

    int n, t; cin >> n >> t;
    for (int i=1; i<=n; i++){
        int x; cin >> x;
        s[i].push({x, 0});
    }
    int cnt = 0;

    for (int i=0; i<t; i++){
        cnt++;
        for (int k=1;k<=n; k++){
            if (s[k].empty()) continue;
            if (s[k].front().second == cnt) continue;

            previ[k] = s[k].front().first;
            s[s[k].front().first].push({k, cnt}); s[k].pop();
        }
    }

    for (int i=1; i<n; i++){
        cout << previ[i] << " ";
    }
    cout << previ[n] << "\n";
}