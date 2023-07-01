#include <bits/stdc++.h>
using namespace std;

const int MAXSZ=1e6+5;

int ans[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    long long n,m, k; cin >> n >> m >> k;

    if (m == 2){
        long long lo = n, hi = (2*n)-1;

        if (k < lo || k > hi){
            cout << "-1\n";
            return 0;
        }

        long long left = n;
        ans[1] = 1;
        left--; k--;
        for (int i=2; i<=n; i++){
            //cout << left << " " << k << "\n";
            if (left == k){
                ans[i] = ans[i-1];
                k--;
            }
            else{
                k -= 2;
                if (ans[i-1] == 1){
                    ans[i] = 2;
                }
                else{
                    ans[i] = 1;
                }
            }
            left--;
        }

        for (int i=1; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << ans[n] << "\n";

    }

    else{
        long long lo = n, hi = (n*(n+1))/2;
        //cout << lo << " " << hi;

        if (k < lo || k > hi){
            cout << "-1\n";
            return 0;
        }

        long long left = n;
        ans[1] = 1;
        left--; k--;
        int cnt = 2;
        for (int i=2; i<=n; i++){
            //cout << left << " " << k << "\n";
            if (left == k){
                ans[i] = ans[i-1];
                k--;
            }
            else{
                if (cnt <= m && k-cnt >= left-1){
                    ans[i] = cnt;
                    k -= cnt;
                    cnt++;
                }
                else{
                    for (int j=cnt-1; j>0; j--){
                        if (k-j >= left-1){
                            ans[i] = ans[i-j];
                            k -= j;
                            break;
                        }
                    }
                }


            }
            left--;
        }

        if (k > 0){
            cout << -1 << "\n";
            return 0;
        }

        for (int i=1; i<n; i++){
            cout << ans[i] << " ";
        }
        cout << ans[n] << "\n";






    }





}