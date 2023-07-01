#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int items[105];
int times[105];
int ks[10005];
int main() {
    int n, t, l, x;
    scan(n);
    scan(t);
    for (int i=0; i<10005; i++){
        ks[i] = -1;
    }
    ks[0] = 0;
    for (int i=0; i<n; i++){
        scan(l);
        for (int k=0; k<l*2; k+=2){
            scan(times[k/2]);
            scan(items[k/2]);
            if (k/2 != 0){
                times[k/2] += times[k/2 - 1];
                items[k/2] += items[k/2 -1];
            }
        }
        for (int k=10005; k>= 0; k--){
            if (ks[k] != -1){
                for (int j = 0; j<l; j++){
                    if (times[j]+k < 10005){
                        ks[times[j]+k] = max(ks[times[j]+k], items[j]+ks[k]);
                    }
                }
            }
        }
    }
    int highest = -1;
    for (int i=0; i<=t; i++){
        highest = max(highest, ks[i]);
    }
    cout << highest << "\n";
}