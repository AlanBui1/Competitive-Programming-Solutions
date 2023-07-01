#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1005;

int arr[MAXSZ][MAXSZ];
int n;

int sum(int x1, int y1, int x2, int y2){
    return arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2] + arr[x1-1][y1-1];
}

int check(int sz){
    int ret = 0;
    sz--;

    for (int i=1; i<=n-sz; i++){
        for (int k=1; k<=n-sz; k++){
            if (sum(i, k, i+sz, k+sz) == 0){
                ret++;
            }
        }
    }
    return ret;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(nullptr);

    cin >> n;

    for (int i=1; i<=n; i++){
        for (int k=1; k<=n; k++){
            cin >> arr[i][k];
            if (arr[i][k] == 0) arr[i][k] = 1;
            else arr[i][k] = 0;
            arr[i][k] += arr[i-1][k] + arr[i][k-1] - arr[i-1][k-1];
        }
    }

    int L = 1, R = n, ans = 0;

    while (L <= R){
        int mid = (L+R)/2;

        int cnt = check(mid);

        if (cnt == 0){
            R = mid-1;
        }
        else{
            L = mid+1;
            ans = mid*cnt;
        }
    }

    cout << ans << "\n";


}