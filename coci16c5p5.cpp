#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=5e5+5;
const int SQRT = 710;

int n,q, ans[MAXSZ], freq[MAXSZ];

int arr[MAXSZ];

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

    int curL=0, curR=0, curAns=0;

    for (int i=0; i<q; i++){
        int QL = qs[i].L, QR = qs[i].R;
        

        while (curL <= QL){ //get inside the range
            if (freq[arr[curL]] == 2) curAns--;
            else if (freq[arr[curL]] == 3) curAns++;
            freq[arr[curL]]--;
            curL++;
        }


        while (curR <= QR){
            if (freq[arr[curR]] == 2) curAns--;
            else if (freq[arr[curR]] == 1) curAns++;
            freq[arr[curR]]++;
            curR++;
        }


        while (curL > QL){
            if (freq[arr[curL-1]] == 2) curAns--;
            else if (freq[arr[curL-1]] == 1) curAns++;
            freq[arr[curL-1]]++;
            curL--;
        }

        while (curR > QR+1){
            if (freq[arr[curR-1]] == 2) curAns--;
            else if (freq[arr[curR-1]] == 3) curAns++;
            freq[arr[curR-1]]--;
            curR--;
        }


        ans[qs[i].I] = curAns;
        

    }

    for (int i=0; i<q; i++){
        cout << ans[i] << "\n";
    }


}

unordered_map <int, int> conv;

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    int cnt = 0;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        if (conv[arr[i]] == 0){
            cnt++;
            conv[arr[i]] = cnt;
            arr[i] = cnt;
        }
        else arr[i] = conv[arr[i]];
    }

    int l, r;

    Query queries[q];

    for (int i=0; i<q; i++){
        Query qu;
        cin >> l >> r;
        qu.L = l-1; qu.R = r-1;
        qu.I = i;

        queries[i] = qu;

    }

    solve(queries);

}