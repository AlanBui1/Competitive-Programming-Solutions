#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    for (int q=0; q<5; q++){
        cin >> n;
        int arr[n];

        int tot=0;
        for (int i=0; i<n; i++){
            cin >> w;
            tot+=w;
            arr[i] = w;
        }
        bool dpOld[tot];
        bool dpNew[tot];
        
        for (int i=0; i<tot; i++){
            dpOld[i] = false;
            dpNew[i] = false;
        }
        dpOld[0] = true;

        for (int i=0; i<n; i++){
            for (int j=0; j<tot; j++){
                dpNew[j] = dpOld[j];
                if (j-arr[i]>=0 and !dpNew[j]){
                    dpNew[j] = dpOld[j-arr[i]];
                }
            }
            for (int j=0; j<tot; j++){
                dpOld[j] = dpNew[j];
            }
        }
        int ans;
        for (int i=tot/2; i>0; i--){
            if (dpNew[i]){
                ans = abs(tot-(2*i));
                break;
            }
        }
        cout << ans << "\n";
    }
}