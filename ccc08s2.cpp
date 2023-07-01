#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int r;
    while (true){
        cin >> r;
        if (!r) return 0;

        int tot = (r+1)*(r+1);
        int rem = 0;
        int R = r*r;

        for (int i=0; i<r+1; i++){
            for (int k=r; k>=0; k--){
                if ((i*i)+(k*k) <= R){
                    break;
                }
                rem++;
            }
        }

        tot -= rem;
        tot *= 4;
        tot -= (4*r);
        tot -= 3;
        cout << tot << "\n";

    }
}