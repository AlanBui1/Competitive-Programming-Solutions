#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 1005;

map <pair <int, pair <int, int>>, int> rects;
pair <int, int> lis[MAXSZ];

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    
    int n; cin >> n;
    for (int i=0; i<n; i++){
        int x, y; cin >> x >> y;
        lis[i].first = x; lis[i].second = y;
    }
    
    for (int i=0; i<n; i++){
        for (int k=i+1; k<n; k++){
            rects[{(lis[i].first - lis[k].first)*(lis[i].first - lis[k].first) + (lis[i].second - lis[k].second)*(lis[i].second - lis[k].second), {(lis[i].first + lis[k].first)/2, (lis[i].second + lis[k].second)/2}}]++;
        }
    }
    int ans = 0;
    for (auto const& [key, val] : rects){
        ans += val*(val-1)/2;
    }
    cout << ans << "\n";
}