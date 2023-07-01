#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 305;

int inds[MAXSZ], want[MAXSZ], ans[MAXSZ], arr[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, q; cin >> n >> q;

    for (int i=1; i<=n; i++){
        inds[i] = i;
        arr[i] = i;
    }

    while (q--){
        char oper; cin >> oper;

        if (oper == 'B'){
            int x, y; cin >> x >> y;
            swap(inds[x], inds[y]);
            swap(arr[inds[x]], arr[inds[y]]);
        }

        else if (oper == 'E'){
            int x, y; cin >> x >> y;
            swap(inds[arr[x]], inds[arr[y]]);
            swap(arr[x], arr[y]);
        }

        else{
            for (int i=1; i<=n; i++){
                cin >> want[i];
            }

            for (int i=1; i<=n; i++){
                ans[arr[i]] = want[i];
            }

            for (int i=1; i<n; i++){
                cout << ans[i] << " ";
            }
            cout << ans[n] << "\n";
        }
    }

}