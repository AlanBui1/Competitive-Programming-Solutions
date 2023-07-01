#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;
    int newDistance[m+1];
    int oldDistance[m+1];

    for (int i=0; i<m+1; i++){
        oldDistance[i] = i;
        newDistance[i] = 0;
    }

    for (int i=1; i<n+1; i++){
        for (int k=0; k<m+1; k++){
            if (i==0 && k==0){
                continue;
            }
            int del = INT_MAX;
            int insert = INT_MAX;
            int replace = INT_MAX;

            if (i>0){
                del = oldDistance[k]+1;
            }
            if (k>0){
                insert = newDistance[k-1]+1;
            }
            if (k>0 && i>0){
                if (a[i-1]==b[k-1]){
                    replace = oldDistance[k-1];
                }
                else{
                    replace = oldDistance[k-1]+1;
                }
            }

            newDistance[k] = min(del, min(insert, replace));
        }
        for (int j=0; j<m+1; j++){
            oldDistance[j] = newDistance[j];
        }    
    }
    int ans=0;
    for (int i=1; i<m; i++){
        ans+=oldDistance[i];
    }
    cout << ans << "\n";
}