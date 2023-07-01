#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=5005;
int n, arr[MAXSZ], mem[MAXSZ], ans, highest;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for (int i=0; i<n; i++){
        ans = 1;
        for (int k=i-1; k>-1; k--){
            if (arr[i] > arr[k]){
                ans = max(ans, mem[k]+1);
            }
        }
        mem[i] = ans;
        highest = max(highest, ans);
    
        
    }
    cout << highest << "\n";
}