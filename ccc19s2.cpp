#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 2e6+5;
bool notPrime[MAXSZ];

bool isPrime(int n){
    if (n == 2 || n == 3) return 1;
    if (n%2 == 0 || n%3 == 0) return 0;

    for (int i=3; i*i <= n; i+=2){
        if (n%i == 0) return 0;
    }

    return 1;
}

void fill(int n){
    int orig = n;
    for (int i=n+orig; i<MAXSZ; i+=orig){
        notPrime[i] = 1;
    }
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    notPrime[0] = 1; notPrime[1] = 1;
    
    fill(2);

    for (int i=3; i<MAXSZ; i+=2){
        if (notPrime[i]) continue;
        if (isPrime(i)){
            fill(i);
        }
    }

    int t; cin >> t;

    while (t--){
        int n; cin >> n;

        n*=2;

        for (int i=3; i<=n/2; i+=2){
            if (!notPrime[i] && !notPrime[n-i]){
                cout << i << " " << n-i << "\n";
                break;
            }
        }
    }

 

}