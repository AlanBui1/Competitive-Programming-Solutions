#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    int heights[10005];
    int width;
    double ans=0.0000000;
    cin >> n;
    for (int i=0; i<n+1; i++){
        cin >> heights[i];
    }
    for (int i=0; i<n; i++){
        cin >> width;
        ans += double(width*(heights[i]+heights[i+1])*0.5);
    }
    cout << fixed << setprecision(6);
    cout << ans << "\n";
    
}