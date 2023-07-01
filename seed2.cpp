#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXSZ=2e9;
int main() {
    string S;

    ll L=1, R=MAXSZ, mid=(L+R)/2;
    ll n = 31;
    while (n--){
        cout << mid << flush << "\n";
        cin >> S ;
        if (S == "OK") return 0;

        if (S == "FLOATS"){
            R = mid-1;
            mid = (L+R)/2;
        }

        else{
            L = mid+1;
            mid = (L+R)/2;
        }
    }
}