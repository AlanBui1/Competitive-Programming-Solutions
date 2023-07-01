#include <bits/stdc++.h>
using namespace std;

const int MAXSZ =1e8+5;
const int nax = 1e4+5;

bitset<MAXSZ>sieve;
//sieve[i] = 1 if i is not prime
int arr[nax], orig[nax];

void solve(){
    int n; cin >>n;

    for (int i=1; i<=n; i++){
        cin >> orig[i];
        arr[i] = orig[i] + arr[i-1];
    }

    bool flag = 0;
    for (int sz = 2; sz <= n; sz++){
        for (int i=1; i<=n; i++){
            if (sz+i-1 > n) break;
            if (!sieve[arr[sz+i-1] - arr[i-1]]){
                cout << "Shortest primed subsequence is length " << sz << ": ";
                for (int k=0; k<sz-1; k++){
                    cout << orig[i+k] << " ";
                }
                cout << orig[i+sz-1] << "\n";
                //cout << i << " " << sz << " " << arr[sz+i] - arr[i-1] << "\n";
                return;
            }
        }
    }


    if (!flag){
        cout << "This sequence is anti-primed.\n";
    }
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    sieve.set(0, 1);
    sieve.set(1, 1);
    for (int i=4; i<MAXSZ; i+=2){
        sieve.set(i, 1);
    }
    for (int i=6; i<MAXSZ; i+=3){
        sieve.set(i, 1);
    }
    for (int i=5; i<MAXSZ; i+=2){
        if (!sieve[i]){
            for (int k=i+i; k<MAXSZ; k+=i){
                sieve.set(k, 1);
            }
        }
    }

    int t; cin >> t;
    while (t--){
        solve();
    }

}