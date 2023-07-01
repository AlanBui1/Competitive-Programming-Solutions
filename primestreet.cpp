#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1300000;
const int MAXSZ = 1e5+5;

bool sieve[MAXN];
int primes[MAXSZ], comps[MAXSZ];

int32_t main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int P = 0, C = 0;

    memset(sieve, 1, sizeof(sieve));
    sieve[0] = 0; sieve[1] = 0;

    for (int i=4; i<MAXN; i+=2){
        sieve[i] = 0;
    }

    for (int i=3; i<MAXN; i+=2){
        if (!sieve[i]){
            continue;
        }
        for (int k=i+i; k<MAXN; k+=i){
            sieve[k] = 0;
        }
    }

    for (int i=2; i<MAXN; i++){
        if (sieve[i]){
            P++;
            if (P < MAXSZ){
                primes[P] = primes[P-1] + i;
            }

        }
        else{
            C++;
            if (C < MAXSZ){
                comps[C] = comps[C-1] + i;
            }

        }
    }

    int N, K; cin >> N >> K;

    int mindif = 9e18, ind = -1;

    for (int i=1; i<=100001-K; i++){
        int primeSum = primes[i + K - 1] - primes[i-1];
        int compSum = comps[i+ K - 1] - comps[i-1];


        if (abs(primeSum - N - compSum) < mindif){
            mindif = abs(primeSum - N - compSum);
            ind= i;
        }
    }
    cout << ind << "\n";


}