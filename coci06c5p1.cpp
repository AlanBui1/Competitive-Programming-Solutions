#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    
    int arr[3] = {1, 0, 0};
    
    string s; cin >> s;
    
    for (char c : s){
        if (c == 'A'){
            swap(arr[0], arr[1]);
        }
        if (c == 'B'){
            swap(arr[1], arr[2]);
        }
        if (c == 'C') {
            swap(arr[0], arr[2]);
        }
    }
    
    for (int i=1; i<=3; i++){
        if (arr[i-1]){
            cout << i << "\n";
            return 0;
        }
    }
    return 0;
}