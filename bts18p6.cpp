#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAXSZ = 1e5+5;

ll arr[MAXSZ];
ll C[MAXSZ], B[MAXSZ], A[MAXSZ], A1[MAXSZ], A2[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, t; cin >> n >> t;

    for (int i=0; i<n; i++){
        ll L, R, a, b, c; cin >> L >> R >> a >> b >> c;

        C[L] += c;
        C[R+1] -= c;

        B[L+1] += b;
        B[R+1] -= b;
        B[R+1] -= (R-L)*b;
        B[R+2] += (R-L)*b;

        A2[L+2] += 2*a;
        A2[R+1] -= 2*a;
        A2[R+1] -= (R-L-1)*2*a;
        A2[R+2] += (R-L-1)*2*a;

        A1[L+1] += a;
        A1[R+1] -= a;

        A[R+1] -= a*(R-L)*(R-L);
        //A[R+2] += a*(R-L)*(R-L);

    }

    for (int i=1; i<=t; i++){
        C[i] += C[i-1];

        A2[i] += A2[i-1];
        A1[i] += A1[i-1];
        //cout << B[i] << " ";
        B[i] += B[i-1];
    }//cout << "\n";

    for (int i=1; i<=t; i++){
        B[i] += B[i-1];
        A2[i] += A2[i-1];
        A[i] += A1[i] + A2[i];
        //cout << B[i] << " ";
    }//cout << "\n";


    for (int i=1; i<=t; i++){
        A[i] += A[i-1];
    }


    for (int i=1; i<=t; i++){
        cout << A[i] + B[i] + C[i] << " ";
    }

}


/*

1 6
1 6 1 3 2

*/