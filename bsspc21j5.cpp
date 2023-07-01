#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6+5;

bool isPrime(int n){

    if (n == 2 || n == 3) return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=3; i*i <=n; i+=2){
        if (n%i == 0) return false;
    }

    return true;
}


vector <int> primes;
int psa[nax];

int main() {
    
    cin.sync_with_stdio(0); cin.tie(0);
    primes.push_back(2);
    psa[0] += 2;
    int cnt = 0;

    for (int i=3; i<nax; i+=2){
        if (isPrime(i)){
            cnt++;
            primes.push_back(i);
            psa[cnt] += i;
            psa[cnt] += psa[cnt-1];
            
        }
    
    }

    int q; cin >> q;
    while (q--){

        int x, k; cin >> x >> k;

        int L = 0, R = cnt; 
    
        int ans = 1e9;

        while (L <= R){
            int mid = (L+R)/2;

            if (primes[mid] == x){
                ans = mid;
                break;
            }

            if (primes[mid] > x){
                ans = min(ans, mid);
                R = mid-1;
            }
            else{
                L = mid+1;
            }
        }

        cout << primes[ans+k-1] << " " << psa[ans+k-1]-psa[ans-1] << "\n";
    
    }
}