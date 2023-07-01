#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e5+5;

int a[MAXSZ], b[MAXSZ], p[MAXSZ], arr[30][MAXSZ], q;

bool works(){
    for (int i=0; i<q; i++){
        for (int k=0; k<26; k++){
            if (arr[k][b[i]] - arr[k][a[i]-1] > 1){
                return false;
            }
        }
    }

    return true;

}



int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    string s; cin >> s;

    int n = s.length();


    cin >> q;
    for (int i=0; i<q; i++){
        cin >> a[i] >> b[i];
    }
    for (int i=0; i<n; i++){
        cin >> p[i];
    }

    for (int i=0; i<n; i++){
        arr[s[i]-'a'][i+1]++;
    }
    s = " "+s;


    int lo = 0, hi = n, ans = n;

    while (lo <= hi){
        int mid = (lo+hi)/2;

        for (int i=0; i<mid; i++){
            arr[s[p[i]] -'a'][p[i]] --;
        }

        for (int i=0; i<26; i++){
            for (int k=1; k<=n; k++){
                arr[i][k] += arr[i][k-1];
            }
        }

        if (works()){
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid+1;
        }

        for (int i=0; i<26; i++){
            for (int k=n; k>=1; k--){
                arr[i][k] -= arr[i][k-1];
            }
        }

        for (int i=0; i<mid; i++){
            arr[s[p[i]] -'a'][p[i]] ++;
        }

    }

    cout << ans << "\n";
}