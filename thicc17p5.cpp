#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
const int MAXF = 1e6+5;
#define ll long long

int main() {

    cin.sync_with_stdio(0); cin.tie(0);

    ll n, k, arr[MAXSZ];
    cin >> n >> k;

    for (int i=0; i<n; i++) cin >> arr[i];
    
    ll cnt=0, freq[MAXF];

    for (int i=0; i<MAXF; i++) freq[i] = 0;

    ll p1=0, p2=0;

    cnt = 1;
    freq[arr[0]] ++;
    ll ans =0;

    while (p1 < n && p2 < n){
        if (cnt >= k){
            
            ans += n-p2;
            freq[arr[p1]] --;
            if (freq[arr[p1]] == 0) cnt--; 
            p1++;
            
        } 

        else{
            
            p2++;
            if (p2 < n){
                freq[arr[p2]]++;
                if (freq[arr[p2]] == 1) cnt++;
            }
        }
    }
    cout << ans << "\n";
}