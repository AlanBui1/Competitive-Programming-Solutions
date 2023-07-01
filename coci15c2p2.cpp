#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair <int, int> arr[405];

bool works(int mask){
    for (pair <int, int> pii : arr){
        if (mask&(1 << pii.f) && mask&(1 << pii.s)) return 0;
    }
    return 1;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    for (int i=0; i<m; i++){
        cin >> arr[i].f >> arr[i].s;
    }

    int highest = 1 << (n+1), ans = 1 << (n+1);

    for (int i=0; i<highest; i++){
        if (!works(i)){
            ans --;
        }
    }

    cout << ans << "\n";
}