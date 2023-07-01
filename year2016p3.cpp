#include <bits/stdc++.h>
using namespace std;

const int MAXSZ = 1e6+5;

int freq[MAXSZ], arr[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    sort(arr, arr+n);
    int ans = -1;

    for (int i=0; i<n; i++){
        for (int k=i+1; k<n; k++){
            // if (arr[i] == arr[k]) continue;
            freq[arr[i]]--;
            freq[arr[k]]--;

            int nextNum = arr[k] + arr[k] - arr[i];
            if (freq[nextNum] > 0){
                ans = max(ans, 3*arr[k]);
            }

            freq[arr[i]]++;
            freq[arr[k]]++;
            
            //cout << arr[i] << " " << arr[k] << " " << nextNum <<" " <<freq[nextNum]<< "\n";
        }
    }
    cout << ans << "\n";
}