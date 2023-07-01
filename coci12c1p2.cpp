#include <bits/stdc++.h>
using namespace std;
const int MAXSZ = 300005;
int points[MAXSZ];
int N;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

bool check(int player){
    for (int i=0; i<N; i++){
        if (i == player){
            continue;
        }
        if (points[player]+N < points[i]+i+1){
            return false;
        }
    }
    return true;
}

int main() {
    scan(N);
    memset(points, -1, sizeof(points));

    for (int i=0; i<N; i++){
        scan(points[i]);
    }
    int n = sizeof(points)/sizeof(points[0]);
    sort(points, points+n, greater<int>());
    int ans=0;
    for (int i=N-1; i>=0; i--){
        
        if (check(i)){
            ans = i+1;
            break;
        }
        else{
            int k=i;
            while (points[k] == points[k-1]){
                i--;
                k--;
            }
        }
    }
    // int ans2=0;
    // for (int i=0; i<N; i++){
    //     if (points[i] >= ans){
    //         ans2++;
    //     }
    //     else{
    //         break;
    //     }
    // }
    cout << ans << "\n";
}