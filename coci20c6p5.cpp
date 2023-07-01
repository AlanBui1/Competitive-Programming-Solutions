#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=2e5+5;
const int SQRT = 450;

int bit[MAXSZ], arr[MAXSZ], ans[MAXSZ];
int n, q;

struct query{
    int L, R, I;
};

void update(int r, int c){
    if (r == 0) return;
    for (; r<MAXSZ; r += (r&-r)){
        bit[r]+= c;
    }
}

int sum(int r){
    int s = 0;
    for (; r>0; r-= (r&-r)){
        s += bit[r];
    }
    return s;
}

bool compare(query x, query y){
    if (x.L / SQRT != y.L / SQRT){
        return x.L / SQRT < y.L /SQRT;
    }
    return x.R < y.R;
}

void solve(query qs[]){
    sort(qs, qs + q, compare);

    int curL = 1, curR = 1;

    for (int i=0; i<q; i++){
        int QL = qs[i].L, QR = qs[i].R;

        while (curL <= QL){
            update(arr[curL], -1);
            curL++;
        }

        while (curR <= QR){
            update(arr[curR], 1);
            curR++;
        }

        while (curR > QR){
            curR --;
            update(arr[curR], -1);
        }

        while (curL > QL){
            curL--;
            update(arr[curL], 1);
        }

        int left = 1, right = MAXSZ-5, a = 0;

        while (left <= right){
            int mid = (left+right)/2;

            if (sum(MAXSZ-1)-sum(mid-1) >= mid){
                a = max(a, mid);
                left = mid+1;
            }
            else{
                right = mid-1; 
            }
        }
 
        ans[qs[i].I] = a;
    }
    for (int i=0; i<q; i++){
        cout << ans[i] << "\n";
    }

}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;

    for (int i=0; i<n; i++) cin >> arr[i+1];

    query qs[q];

    for (int i=0; i<q; i++){
        int l, r; cin >> l >> r;
        query Q; Q.L = l; Q.R = r+1; Q.I = i;
        qs[i] =Q;
    }

    solve(qs);

}