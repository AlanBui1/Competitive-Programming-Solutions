#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e3+5;
#define ll long long

ll arr[MAXSZ];

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    int vals[MAXSZ];
    for (int i=0; i<n; i++){
        cin >> vals[i];
    }    

    for (int i=0; i<n; i++){
        for (int k=0; k <n; k++){
            if (i+k+1 <=n){
                arr[i+1+k] = max(arr[i+k+1], arr[k]+vals[i]);
            }
        }
    }
    cout << arr[n] << "\n";
}