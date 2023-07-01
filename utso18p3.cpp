#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e6+5;

int bit[MAXSZ], n, k, t, v;
bool rest[MAXSZ];

void update(int i){
    for (; i<=MAXSZ; i+= (i&-i)){
        bit[i]++;
    }
}

int sum(int r){
    int s = 0;

    for (; r>0; r -= (r&-r)){
        s += bit[r];
    }

    return s;
}

int query(int l, int r){
    return sum(r)-sum(l-1);
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0); 

    cin >> n >> t >> k >> v;

    for (int i=0; i<v; i++){
        int x; cin >> x;
        update(x);
        rest[x] = 1;
    }

    int cost = 0;
    
    for (int i=1; i<=n-t+1; i++){
        int amt = query(i, i+t-1);
        if (amt < k){
            cost+=k-amt;
            int cnt=i+t-1;

            int needtoupdate = k-amt;
            while (needtoupdate){
                if (!rest[cnt]){
                    rest[cnt] = 1;
                    update(cnt);
                    needtoupdate--;
                }    
                cnt--;
            }
           
        }
    }

    cout << cost << "\n";
}