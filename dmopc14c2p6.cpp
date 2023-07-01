#include <bits/stdc++.h>
using namespace std;
const int MAXSZ=1e5+5;
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
#define f first
#define se second

vector <pair<int, int>> arr;
int n, q;

struct segTree{
    int L, R, val;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;
    s.val = 0;
    if (left != right){
        int mid = (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
    }
}

int sumQuery(int curNode, int QL, int QR){
    int L = s.L, R = s.R;

    if (L > QR ||R < QL){
        return 0;
    }

    else if (QL <= L && R <= QR){
        return s.val;
    }

    return sumQuery(curNode*2, QL, QR)+sumQuery(curNode*2+1, QL, QR);
}

void update(int curNode, int idx, int newVal){
    int L=s.L, R=s.R;
    
    if (L > idx || R < idx) return;

    if (L==R && L == idx){
        s.val = newVal;
        return;
    }

    update(curNode*2, idx, newVal); update(curNode*2+1, idx, newVal);
    s.val = cl.val+cr.val;
}


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> n;
    buildTree(1, 0, n-1);
    int v;
    for (int i=0 ; i<n; i++){
        cin >> v;
        arr.push_back({v, i});
    }

    cin >> q;
    int l, r, x;

    vector <pair <int, pair <int, pair <int, int>>>> queries;
    int ans[q];
    for (int i=0; i<q; i++){
        cin >> l >> r >> x;

        queries.push_back({x, {l, {r, i}}});

    }

    sort(queries.begin(), queries.end());

    int X, L, R, I;
    sort(arr.begin(), arr.end());
    int curTree = n-1;

    for (int i=q-1; i>=0; i--){

        X = queries[i].f;
        L = queries[i].se.f;
        R = queries[i].se.se.f;
        I = queries[i].se.se.se;

        if (curTree >= 0){
            while (arr[curTree].f >= X){
                update(1, arr[curTree].se, arr[curTree].f);
                curTree--;
                if (curTree < 0) break;
            }
        }

        ans[I] = sumQuery(1, L, R);
    }

    for (int i=0; i<q; i++) cout << ans[i] << "\n";

}