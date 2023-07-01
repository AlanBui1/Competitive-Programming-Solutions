#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 30;

string arr[MAXSZ];
int n, ans;
int words[MAXSZ];
int freq;

void recur(int cur, int ind, int added){
    if (cur == (1 << 26)-1) ans+= added;
    if (ind == n) return;
    recur(cur | words[ind], ind+1, 1);
    recur(cur, ind+1, 0);
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        for (char c : arr[i]){
            words[i] |= (1 << (c-'a'));
        }
    }
    recur(0,0,0);
    cout << ans << "\n";

}