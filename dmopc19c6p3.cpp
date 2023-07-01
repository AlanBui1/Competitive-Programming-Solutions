#include <bits/stdc++.h>
using namespace std;
const int nax = 5e5+5;
#define ll long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]
const int MOD=1e9+7;

char arr[nax];
struct segTree{
    int L, R;
    ll val, fval;
}seg[nax*4];

ll powers[nax];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right; s.fval = powers[right]-powers[left-1];

    if (left == right){
        s.val = (arr[left] == '1')*s.fval;
    }
    else{
        int mid= (left+right)/2;
        buildTree(curNode*2, left, mid);
        buildTree(curNode*2+1, mid+1, right);
        s.val = cl.val+cr.val;
        s.val %= MOD;
    }
}

void update(int curNode, int UL, int UR){
    int L = s.L, R = s.R;

    if (L > UR || R< UL || s.val == s.fval) return;

    if (UL <= L && R <= UR){
        s.val = s.fval;
        return;
    }
    update(curNode*2, UL, UR); 
    update(curNode*2+1, UL, UR);
    s.val = cl.val+cr.val;
    s.val %= MOD;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    powers[n-1] = 1;
    for (int i=1; i<n; i++){
        powers[n-i-1] = (powers[n-i]*2)%MOD;
        powers[n-i-1] %= MOD;
    }

    for (int i=1; i<n; i++){
        powers[i] += powers[i-1];
    } 


    buildTree(1, 0, n-1);
    int L, R;

    while (m--){
        cin >> L >> R;
        update(1, L-1, R-1);
        cout << seg[1].val%MOD << "\n";
    }

}