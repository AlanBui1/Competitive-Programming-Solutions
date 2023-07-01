#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 1e5+5;

int n, MOD, arr[MAXSZ], psa[MAXSZ];
unordered_map <int, int> freq;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> MOD;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        arr[i] %= MOD;
        psa[i] = psa[i-1] + arr[i];
        psa[i] %= MOD;
        freq[psa[i]]++;
    }

    /*for (pair <int, int> PII : freq){
        cout << PII.first << " " << PII.second << "\n";
    }*/

    long long ans = 0, want=0;
    for (int i=0; i<n; i++){
        want += arr[i];

        want %= MOD;
        if (i > 0) freq[psa[i]]--;
        //cout << want << " " << freq[want] << "\n";

        ans += freq[want];
    }

    cout << ans << "\n";
}