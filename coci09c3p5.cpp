#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=3e5+5;
const int MAXC = 1e4+5;
const int SQRT = 550;

int n , c, q, arr[MAXSZ], freq[MAXC], ans[MAXC];

struct Query{
    int L, R, I;
};

bool compare(Query x, Query y){
    if (x.L / SQRT != y.L / SQRT){
        return x.L / SQRT < y.L / SQRT;
    }
    return x.R < y.R;
}

void solve(Query qs[]){
    sort(qs, qs+q, compare);

    int curL = 0, curR = 0, curDom = 0;

    for (int i=0; i<q; i++){
        int QL = qs[i].L, QR = qs[i].R;
        curDom = -1;

        while (curL <= QL){
            freq[arr[curL]] --;
            // if (freq[arr[curL]] > (QR-QL+1)/2){
            //     curDom = arr[curL];
            // }
            curL ++;
        }

        while (curR > QR+1){
            freq[arr[curR-1]] --;
            // if (freq[arr[curR-1]] > (QR-QL+1)/2){
            //     curDom = arr[curR-1];
            // }
            curR --;
        }

        while (curL > QL){
            freq[arr[curL-1]] ++;
            // if (freq[arr[curL-1]] > (QR-QL+1)/2){
            //     curDom = arr[curL-1];
            // }
            curL--;
        }

        while (curR <= QR){
            freq[arr[curR]]++;
            // if (freq[arr[curR]] > (QR-QL+1)/2){
            //     curDom = arr[curR];
            // }
            curR++;
        }

        for (int i=1;i <=c; i++){
            if (freq[i] > (QR-QL+1)/2){
                curDom = i; break;
            }
        }

        if (freq[curDom] <= (QR-QL+1)/2 || curDom == -1) ans[qs[i].I] = -1;
        else ans[qs[i].I] = curDom;
    }

    for (int i=0; i<q; i++){
        if (ans[i] == -1) cout << "no\n";
        else cout << "yes " << ans[i] << "\n";

    }

}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> c;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> q;
    Query queries[q];
    
    for (int i=0;i <q; i++){
        int l, r; cin >> l >> r;
        l--; r--;
        Query qu; qu.L = l; qu.R = r; qu.I = i;
        queries[i]= qu;
    }

    solve(queries);

}