#include <bits/stdc++.h>

using namespace std;

const int nax = 1e3+5;

int matrix[nax][nax];
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    
    for (int i=0; i<n; i++){
        for (int k=0; k<n; k++){
            cin >> matrix[i][k];
        }
    }
    
    if (n == 2){
        cout << "1 1\n";
    }
    else{
        int A = (matrix[0][1]+matrix[0][2] - matrix[1][2])/2;
        cout << A << " ";
        for (int i=1; i<n-1; i++){
            cout << matrix[0][i]-A << " ";
        }
        cout << matrix[0][n-1]-A << "\n";
    }
    return 0;
}