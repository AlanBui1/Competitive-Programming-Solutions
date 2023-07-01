#include <bits/stdc++.h>
using namespace std;

#define int long long
#define s seg[curNode]
#define cl seg[curNode*2]
#define cr seg[curNode*2+1]

const int MAXSZ = 1e5+5;
int n, k, d, arr[MAXSZ];

struct node{
    int L, R, lazy, val;
}seg[MAXSZ*4];

void buildTree(int curNode, int left, int right){
    s.L = left; s.R = right;
    s.lazy = 1; s.val = 1;
    if (left == right){
        return;
    }

    int mid = (left+right)/2;
    buildTree(curNode*2, left, mid);
    buildTree(curNode*2+1, mid+1, right);
}

void update(int curNode, int mult, int UL, int UR){
    int L = s.L, R = s.R;

    if (L > UR || R < UL) return;
    if (UL <= L && R <= UR){
        s.lazy *= mult;
        s.lazy = min(s.lazy, d+1);
        return;
    }

    update(curNode*2, mult, UL, UR);
    update(curNode*2+1, mult, UL, UR);
}

void pushLazy(int curNode){
    int L = s.L, R= s.R;

    if (L == R){
        s.val *= s.lazy;
        s.lazy = 1;
        arr[L] = s.val;
        return;
    }

    cl.lazy *= s.lazy;
    cl.lazy = min(cl.lazy, d+1);
    cr.lazy *= s.lazy;
    cr.lazy = min(cr.lazy, d+1);
    s.lazy = 1;
    pushLazy(curNode*2); pushLazy(curNode*2+1);
}


signed main(){
    cin.sync_with_stdio(0);
    cin.tie(0);



    cin >> n >> k >> d;
    int num = 0;

    buildTree(1, 1, n);

    while (n--){
        char op; cin >> op;

        if (op == 'T'){
            num++;
        }
        else{
            int q; cin >> q;
            update(1, q, 1, num);
        }
    }

    pushLazy(1);

    for (int i=1; i<=num; i++){
        if (arr[i] > d){
            cout << "dust\n";
        }
        else{
            cout << arr[i] << "\n";
        }
    }

}