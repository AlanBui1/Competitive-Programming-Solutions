#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i=0; i<n; i++){
        int a, b;
        cin >> a >> b;
        int ans=0;
        int tot = a*b;
        if ((tot)%2 == 1){
            ans++;
            tot--;
        }

        ans += tot;
        ans --;
        cout << ans <<"\n";
    }

}