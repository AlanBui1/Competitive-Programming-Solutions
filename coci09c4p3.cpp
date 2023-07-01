#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nax = 1e6+5;

bool sieve[nax];

int n;
int arr[105];
map <int, int> factors;

bool prime(int x){
    if (x == 2 || x == 3) return true;
    if (x%2 == 0 || x%3 == 0) return false;

    for (int i=3; i*i <= x; i+=2){
        if (x%i == 0) return false;
    }
    return true;
}

void push(int x){
    int s = 2*x;

    while (s < nax){
        sieve[s] = 1;
        s += x;
    }
}

int f(int a, int x){
    int cnt = 0;
    while (a%x == 0){
        cnt++;
        a/=x;
    }
    return cnt;
}

void add(int a, int x){
    factors[x] += f(a, x);
}

void factorize(int x){
    for (int i=1; i*i <= x; i++){
        if (x%i == 0){
            int f1 = i, f2 = x/i;
            if (f1 == f2) f2 = 1;
            if (!sieve[f1]) add(x, f1);
            if (!sieve[f2]) add(x, f2);
        }
    }
}

int power(int base, int exp){
    if (exp == 0) return 1;

    int mult = base, start = base;

    while (exp > 0){
        if (exp&1){
            base *= mult;
        }
        exp/=2; mult *= mult;
    }
    return base/start;
}

int32_t main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<nax; i++) sieve[i] = 0;


    push(2);
    for (int i=3; i<nax; i+=2){
        if (sieve[i]) continue;
        if (prime(i)){
            push(i);
        }
    }
    sieve[0] = 1;
    sieve[1] = 1;


    for (int i=0; i<n; i++){
        factorize(arr[i]);
    }

    int ans = 1;
    for (pair <int, int> i : factors){
        factors[i.first] /= n;
        ans *= power(i.first, factors[i.first]);
    }

    int moves =0 ;

    for (int i=0; i<n; i++){
        for (pair <int, int> pii : factors){
            moves += max(0ll, pii.second - f(arr[i], pii.first));
            //cout << pii.first << " " << pii.second << "\n";
        }
    }

    cout << ans << " " << moves << "\n";


}