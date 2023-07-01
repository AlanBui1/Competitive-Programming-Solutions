#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e6+5;
const int inc = 1e6;
int x[MAXSZ], y[MAXSZ];
long long dist=0;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >>n >> m;
    for (int i=0; i<n; i++){
        int a,b; cin >> a >> b;
        dist += abs(a)+abs(b);
        x[a+inc]++; y[b+inc]++;
    }

    for (int i=1; i<MAXSZ; i++){
        x[i] += x[i-1];
        y[i] += y[i-1];
    }
    int curX = 0, curY = 0;
    while (m--){
        char c; cin >> c;

        if (c == 'S'){
            curY++;
            dist -= y[MAXSZ-1] - y[curY+inc-1];
            dist += y[curY+inc-1];
        }

        if (c == 'J'){
            curY --;
            dist -= y[curY+inc];
            dist += y[MAXSZ-1] - y[curY+inc];
        }

        if (c == 'I'){
            curX++;
            dist -= x[MAXSZ-1] - x[curX+inc-1];
            dist += x[curX+inc-1];
        }

        if (c == 'Z'){
            curX--;
            dist -= x[curX+inc];
            dist += x[MAXSZ-1] - x[curX+inc];
        }

        cout << dist << "\n";
    }
}