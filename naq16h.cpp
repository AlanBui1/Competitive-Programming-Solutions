#include <bits/stdc++.h>
using namespace std;
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

const int MAXSZ = 100005;
int hotdogs[MAXSZ];
int buns[MAXSZ];
int main() {
    int h, b, Hi, Bi;
    int highest = 0;
    // memset(hotdogs, 10000000, sizeof(hotdogs));
    // memset(buns, 10000000, sizeof(buns));
    for (int i=0; i<MAXSZ; i++){
        hotdogs[i] = 10000000; buns[i] = 10000000;
    }
    scan(h);
    hotdogs[0] = 0;
    buns[0] = 0;
    for (int i=0; i<h; i++){
        scan(Hi);
        for (int k=highest; k>= 0; k--){
            if (hotdogs[k] != 10000000  ){
                hotdogs[k+Hi] = min(hotdogs[k+Hi], hotdogs[k]+1);
                highest = max(highest, Hi+k);
            }
        }

    }
    scan(b);
    highest = 0;
    for (int i=0; i<b; i++){
        scan(Bi);
        for (int k=highest; k>= 0; k--){
            if (buns[k] != 10000000){
                buns[k+Bi] = min(buns[k+Bi], buns[k]+1);
                highest = max(highest, Bi+k);
            }
        }

    }
    int smallest = 10000000;
    for (int i=1; i<MAXSZ; i++){
        smallest = min(smallest, buns[i]+hotdogs[i]);
    }
    if (smallest == 10000000){
        cout << "impossible\n";
        return 0;
    }   
    cout << smallest << "\n";
    // for (int i=0; i<MAXSZ; i++){
    //     cout << hotdogs[i] << " "<< buns[i] << "\n";
    // }
}