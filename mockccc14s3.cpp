#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 105;

int arr[MAXSZ][MAXSZ];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);


    int r, c; cin >> r >> c;

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            cin >> arr[i][k];
        }
    }

    int n; cin >> n;
    //assert(n < 0);

    while (n--){
        int col; cin >> col;

        for (int i=1; i<=r; i++){
            for (int k=1; k<r; k++){
                if (arr[k+1][col] < arr[k][col]){
                    swap(arr[k], arr[k+1]);
                }
            }
        }
    }

    for (int i=1; i<=r; i++){
        for (int k=1; k<=c; k++){
            cout << arr[i][k];
            if (k != c) cout << " ";
        }
        cout << "\n";
    }
}