#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int MAXSZ = 505;

int blame[MAXSZ][MAXSZ];
ll dist[MAXSZ][MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    ll n, k, ind = 1; cin >> n >> k;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            cin >> blame[i][j];
            if (i == 1 && blame[i][j] == 2) ind = j;
        }
    }

    if (k == 1){
        cout << 1 << "\n";
        return 0;
    }

    dist[1][ind] = 1;

    ll prev = 1, person = 2, cnt = 2;

    for (int i=0; i<k-2; i++){
        ll temp = person;
        if (dist[person][prev] != 0){
            break;
        }
        dist[person][prev] = cnt;
        person = blame[person][prev];

        prev = temp;
        cnt++;
    }
    //cout << person<< " " << prev << " " << cnt << "\n";
    ll cycle = cnt - dist[person][prev];
    assert(cycle != 0);
    k = (k-dist[person][prev])%cycle;

    for (int i=0; i<k; i++){
        ll temp = person;
        person = blame[person][prev];

        prev = temp;
    }

    cout << person << "\n";


}